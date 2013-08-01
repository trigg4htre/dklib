#include "DK3ds.h"

//////////////////////////////////////////////////////////
DK3ds::DK3ds(DKObject *parent, DKString file, DKPoint pos)
{   
	Create(parent,file,pos);
}

////////////////////////////////////////////////////////////////
void DK3ds::Create(DKObject *parent, DKString file, DKPoint pos)
{
	DKObject::Create(parent, "DK3ds");
	point = pos;

	model = lib3ds_file_open(file.c_str());

	// No nodes?  Fabricate nodes to display all the meshes.
    if (!model->nodes) {
        Lib3dsNode *node;
        int i;
        for (i = 0; i < model->nmeshes; ++i) {
            Lib3dsMesh *mesh = model->meshes[i];
            node = lib3ds_node_new(LIB3DS_NODE_MESH_INSTANCE);
            strcpy(node->name, mesh->name);
            lib3ds_file_insert_node(model, node, NULL);
        }
    }

	lib3ds_file_eval(model, 0.0f);
    lib3ds_file_bounding_box_of_nodes(model, 1, 0, 0, bmin, bmax, NULL);
    sx = bmax[0] - bmin[0];
    sy = bmax[1] - bmin[1];
    sz = bmax[2] - bmin[2];
    size = MAX(sx, sy);
    size = MAX(size, sz);
    cx = (bmin[0] + bmax[0]) / 2;
    cy = (bmin[1] + bmax[1]) / 2;
    cz = (bmin[2] + bmax[2]) / 2;

	// No cameras in the file?  Add four 
	if (!model->ncameras) {
        // Add some cameras that encompass the bounding box
        Lib3dsCamera *camera = lib3ds_camera_new("Camera_X");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[0] = bmax[0] + 1.5f * MAX(sy, sz);
        camera->near_range = (camera->position[0] - bmax[0]) * 0.5f;
        camera->far_range = (camera->position[0] - bmin[0]) * 2.0f;
        lib3ds_file_insert_camera(model, camera, -1);

        // Since lib3ds considers +Y to be into the screen, we'll put
		// this camera on the -Y axis, looking in the +Y direction.

        camera = lib3ds_camera_new("Camera_Y");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[1] = bmin[1] - 1.5f * MAX(sx, sz);
        camera->near_range = (bmin[1] - camera->position[1]) * 0.5f;
        camera->far_range = (bmax[1] - camera->position[1]) * 0.2f;
        lib3ds_file_insert_camera(model, camera, -1);

        camera = lib3ds_camera_new("Camera_Z");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[2] = bmax[2] + 1.5f * MAX(sx, sy);
        camera->near_range = (camera->position[2] - bmax[2]) * 0.5f;
        camera->far_range = (camera->position[2] - bmin[2]) * 2.0f;
        lib3ds_file_insert_camera(model, camera, -1);

        camera = lib3ds_camera_new("Camera_ISO");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[0] = bmax[0] + 0.75f * size;
        camera->position[1] = bmin[1] - 0.75f * size;
        camera->position[2] = bmax[2] + 0.75f * size;
        camera->near_range = (camera->position[0] - bmax[0]) * 0.5f;
        camera->far_range = (camera->position[0] - bmin[0]) * 3.0f;
        lib3ds_file_insert_camera(model, camera, -1);
    }

	// No lights in the file?  Add some.
    if (!model->nlights) {
        Lib3dsLight *light;

        light = lib3ds_light_new("light0");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = 0.6f;
        light->position[0] = cx + size * 0.75f;
        light->position[1] = cy - size * 1.0f;
        light->position[2] = cz + size * 1.5f;
        light->position[3] = 0.;
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(model, light, -1);

        light = lib3ds_light_new("light1");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = 0.3f;
        light->position[0] = cx - size;
        light->position[1] = cy - size;
        light->position[2] = cz + size * 0.75f;
        light->position[3] = 0.;
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(model, light, -1);

        light = lib3ds_light_new("light2");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = 0.3f;
        light->position[0] = cx;
        light->position[1] = cy + size;
        light->position[2] = cz + size;
        light->position[3] = 0.;
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(model, light, -1);
    }

	 camera = model->cameras[0]->name;

    for (int i = 0; i < model->nmaterials; ++i) {
        Lib3dsMaterial *mat = model->materials[i];
        if (mat->texture1_map.name[0]) {  // texture map? 
            Lib3dsTextureMap *tex = &mat->texture1_map;

            char texname[1024];
            PlayerTexture *pt = (PlayerTexture*)calloc(sizeof(*pt),1);
            tex->user_ptr = pt;
            strcpy(texname, datapath);
            strcat(texname, "/");
            strcat(texname, tex->name);

            printf("Loading %s\n", texname);
			SDL_Surface* img = IMG_Load(texname);
			if(img != NULL){
				//, &pt->pixels, &pt->w, &pt->h)) {
				//pt->pixels = img->pixels;
				pt->w = img->w;
				pt->h = img->h;
                glGenTextures(1, &pt->tex_id);

                glBindTexture(GL_TEXTURE_2D, pt->tex_id);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->w, img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);
                //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            } else {
                fprintf(stderr, "Loading '%s' failed!\n", texname);
            }
        }
    }

    lib3ds_file_eval(model, 0);

	SetVisibility(true);
}

///////////////
DK3ds::~DK3ds()
{

}

/////////////////////
void DK3ds::Display()
{
	if(NotVisible()){return;}

	Lib3dsTargetNode *t;
    Lib3dsCameraNode *c;
    float fov;
	float roll;
    float near2;
	float far2;
	float dist;
    float *campos;
    float *tgt;
    float M[4][4];
    int camidx;
    Lib3dsCamera *cam;
    float v[3];
    Lib3dsNode *p;

    if (model != NULL && model->background.use_solid)
        glClearColor(model->background.solid_color[0],
                     model->background.solid_color[1],
                     model->background.solid_color[2], 1.);

    /* TODO: fog */

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // if (anti_alias)
   //     glEnable(GL_POLYGON_SMOOTH);
   // else
    //    glDisable(GL_POLYGON_SMOOTH);


    if (!model) {
        return;
    }

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model->ambient);

    c = (Lib3dsCameraNode*)lib3ds_file_node_by_name(model, camera.c_str(), LIB3DS_NODE_CAMERA);
    t = (Lib3dsTargetNode*)lib3ds_file_node_by_name(model, camera.c_str(), LIB3DS_NODE_CAMERA_TARGET);

    if (t != NULL) {
        tgt = t->pos;
    }
    if (c != NULL) {
        fov = c->fov;
        roll = c->roll;
        campos = c->pos;
    }

    if ((camidx = lib3ds_file_camera_by_name(model, camera.c_str())) == -1)
        return;

    cam = model->cameras[camidx];
    near2 = cam->near_range;
    far2 = cam->far_range;

    if (c == NULL || t == NULL) {
        if (c == NULL) {
            fov = cam->fov;
            roll = cam->roll;
            campos = cam->position;
        }
        if (t == NULL)
            tgt = cam->target;
    }

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    /* KLUDGE alert:  OpenGL can't handle a near clip plane of zero,
    * so if the camera's near plane is zero, we give it a small number.
    * In addition, many .3ds files I've seen have a far plane that's
    * much too close and the model gets clipped away.  I haven't found
    * a way to tell OpenGL not to clip the far plane, so we move it
    * further away.  A factor of 10 seems to make all the models I've
    * seen visible.
    */
    if (near2 <= 0.) near2 = far2 * 0.001f;

    //gluPerspective(fov, 1.0*gl_width / gl_height, 1, 10000);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
   // glRotatef(-90, 1.0, 0, 0);

    /* User rotates the view about the target point */

    lib3ds_vector_sub(v, tgt, campos);
    dist = lib3ds_vector_length(v);

    //glTranslatef(0., dist, 0.);
    //glRotatef(view_rotx, 1., 0., 0.);
    //glRotatef(view_roty, 0., 1., 0.);
    //glRotatef(view_rotz, 0., 0., 1.);
    //glTranslatef(0., -dist, 0.);

    lib3ds_matrix_camera(M, campos, tgt, roll);
    glMultMatrixf(&M[0][0]);

    /* Lights.  Set them from light nodes if possible.  If not, use the
    * light objects directly.
    */
    {
        static const GLfloat a[] = {0.0f, 0.0f, 0.0f, 1.0f};
        static GLfloat c[] = {1.0f, 1.0f, 1.0f, 1.0f};
        static GLfloat p[] = {0.0f, 0.0f, 0.0f, 1.0f};
        Lib3dsLight *l;
        int i;

        int li = GL_LIGHT0;
        for (i = 0; i < model->nlights; ++i) {
            l = model->lights[i];
            glEnable(li);
            //light_update(l);

            c[0] = l->color[0];
            c[1] = l->color[1];
            c[2] = l->color[2];
            glLightfv(li, GL_AMBIENT, a);
            glLightfv(li, GL_DIFFUSE, c);
            glLightfv(li, GL_SPECULAR, c);

            p[0] = l->position[0];
            p[1] = l->position[1];
            p[2] = l->position[2];
            glLightfv(li, GL_POSITION, p);

            if (l->spot_light) {
                p[0] = l->target[0] - l->position[0];
                p[1] = l->target[1] - l->position[1];
                p[2] = l->target[2] - l->position[2];
                glLightfv(li, GL_SPOT_DIRECTION, p);
            }
            ++li;
        }
    }

    //if (show_object) {
        for (p = model->nodes; p != 0; p = p->next) {
            render_node(p);
        }
    //}

   // if (show_bounds)
        //draw_bounds(tgt);

		/*
    if (show_cameras) {
        int i;
        for (i = 0; i < model->ncameras; ++i) {
            cam = model->cameras[i];
            lib3ds_matrix_camera(M, cam->position, cam->target, cam->roll);
            lib3ds_matrix_inv(M);

            glPushMatrix();
            glMultMatrixf(&M[0][0]);
            glScalef(size / 20, size / 20, size / 20);
            glCallList(cameraList);
            glPopMatrix();
        }
    }
	*/

	/*
    if (show_lights) {
        Lib3dsLight *light;
        int i;
        for (i = 0; i < model->nlights; ++i) {
            light = model->lights[i];
            draw_light(light->position, light->color);
        }
        glMaterialfv(GL_FRONT, GL_EMISSION, black);
    }
	*/
}


/////////////////////////////////////////
void DK3ds::render_node(Lib3dsNode *node)
{
    //assert(file);

    {
        Lib3dsNode *p;
        for (p = node->childs; p != 0; p = p->next) {
            render_node(p);
        }
    }
    if (node->type == LIB3DS_NODE_MESH_INSTANCE) {
        int index;
        Lib3dsMesh *mesh;
        Lib3dsMeshInstanceNode *n = (Lib3dsMeshInstanceNode*)node;

        if (strcmp(node->name, "$$$DUMMY") == 0) {
            return;
        }

        index = lib3ds_file_mesh_by_name(model, n->instance_name);
        if (index < 0)
            index = lib3ds_file_mesh_by_name(model, node->name);
        if (index < 0) {
            return;
        }
        mesh = model->meshes[index];

        if (!mesh->user_id) {
            //assert(mesh);

           // mesh->user_id = glGenLists(1);
           // glNewList(mesh->user_id, GL_COMPILE);

            {
                int p;
                float (*normalL)[3] = (float(*)[3])malloc(3 * 3 * sizeof(float) * mesh->nfaces);
                Lib3dsMaterial *oldmat = (Lib3dsMaterial *) - 1;
                {
                    float M[4][4];
                    lib3ds_matrix_copy(M, mesh->matrix);
                    lib3ds_matrix_inv(M);
                    glMultMatrixf(&M[0][0]);
                }
                lib3ds_mesh_calculate_vertex_normals(mesh, normalL);

                for (p = 0; p < mesh->nfaces; ++p) {
                    Lib3dsMaterial *mat = 0;

                    if (mesh->faces[p].material >= 0) {
                        mat = model->materials[mesh->faces[p].material];
                    }

                    if (mat != oldmat) {
                        if (mat) {
                            //if (mat->two_sided)
                            //    glDisable(GL_CULL_FACE);
                            //else
                            //    glEnable(GL_CULL_FACE);
                            //
                            //glDisable(GL_CULL_FACE);

                            if (mat->texture1_map.user_ptr) {
                                PlayerTexture* pt = (PlayerTexture*)mat->texture1_map.user_ptr;
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D, pt->tex_id);
                            } else {
                                glDisable(GL_TEXTURE_2D);
                            }

                            {
                                float a[4], d[4], s[4];
                                int i;
                                for (i=0; i<3; ++i) {
                                    a[i] = mat->ambient[i];
                                    d[i] = mat->diffuse[i];
                                    s[i] = mat->specular[i];
                                }
                                a[3] = d[3] = s[3] = 1.0f;
                                
                                glMaterialfv(GL_FRONT, GL_AMBIENT, a);
                                glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
                                glMaterialfv(GL_FRONT, GL_SPECULAR, s);
                            }
                            float shininess = pow(2.0f, 10.0f*mat->shininess);
                            glMaterialf(GL_FRONT, GL_SHININESS, shininess <= 128? shininess : 128);
                        } else {
                            static const float a[4] = {0.7f, 0.7f, 0.7f, 1.0f};
                            static const float d[4] = {0.7f, 0.7f, 0.7f, 1.0f};
                            static const float s[4] = {1.0f, 1.0f, 1.0f, 1.0f};
                            glMaterialfv(GL_FRONT, GL_AMBIENT, a);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, s);
                            glMaterialf(GL_FRONT, GL_SHININESS, pow(0.2f, 10.0f*0.5f));
                        }
                        oldmat = mat;
                    }

                    {
                        /*{
                            float v1[3], n[3], v2[3];
                            glBegin(GL_LINES);
                            for (i = 0; i < 3; ++i) {
                                lib3ds_vector_copy(v1, mesh->vertices[f->points[i]]);
                                glVertex3fv(v1);
                                lib3ds_vector_copy(n, normalL[3*p+i]);
                                lib3ds_vector_scalar(n, 10.f);
                                lib3ds_vector_add(v2, v1, n);
                                glVertex3fv(v2);
                            }
                            glEnd();
                        }*/

						/*
                        glBegin(GL_TRIANGLES);
                        for (int i = 0; i < 3; ++i) {
                            glNormal3fv(normalL[3*p+i]);

                            if (mat->texture1_map.user_ptr) {
                                glTexCoord2f(
                                    mesh->texcos[mesh->faces[p].index[i]][0],
                                    1-mesh->texcos[mesh->faces[p].index[i]][1] );
                            }

                            glVertex3fv(mesh->vertices[mesh->faces[p].index[i]]);
                        }
                        glEnd();
						*/
                    }
                }

                free(normalL);
            }

            glDisable(GL_TEXTURE_2D);
            //glEndList();
        }

        if (mesh->user_id) {
            glPushMatrix();
            glMultMatrixf(&node->matrix[0][0]);
            glTranslatef(-n->pivot[0], -n->pivot[1], -n->pivot[2]);
            //glCallList(mesh->user_id);
            glPopMatrix();

        }
    }
}
