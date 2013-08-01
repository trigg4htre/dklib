#include "DKFrameBase.h"

DKFrameBase::DKFrameBase()
{
	//Camera
	eye_x = 1.0;
	eye_y = 1.0;
	eye_z = 1.0;
	target_x = 0;
	target_y = 0;
	target_z = 0;
	up_x = 0;
	up_y = -1.0;
	up_z = 0;
	rot_x = 0;
	rot_y = 0;
	rot_z = 0;
	trans_x = 0;
	trans_y = 0;
	trans_z = -1000.0;
	distance = 2000;
}

//////////////////////////////////////
void DKFrameBase::Setup2D(DKSize size)
{
	glDisable(GL_DEPTH_TEST);
	glViewport(0, 0, (int)size.x, (int)size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	glOrtho(0.0f, size.x, size.y, 0.0f, -0.1f, 0.1f);
#endif
#if  defined (ANDROID) || (IOS)
	glOrthof(0.0f, size.x, size.y, 0.0f, -0.1f, 0.1f );
#endif
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//////////////////////////////////////
void DKFrameBase::Setup3D(DKSize size)
{

#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
    glClearDepth(1.0f);
#endif
#if defined (ANDROID) || (IOS)
	glClearDepthf(1.0f);
#endif
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    //glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_COLOR_MATERIAL);

	int topleft_x = 0;
	int topleft_y = 0;
	int bottomrigth_x = (int)size.x;
	int bottomrigth_y = (int)size.y;

    glViewport(topleft_x, topleft_y, bottomrigth_x-topleft_x, bottomrigth_y-topleft_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio_w_h = (float)(bottomrigth_x-topleft_x)/(float)(bottomrigth_y-topleft_y);

    Perspective(45, ratio_w_h, 0.1, distance);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glRotatef(rot_x,1.0,0.0,0.0); // Rotate on x
    glRotatef(rot_y,0.0,1.0,0.0); // Rotate on y
    glRotatef(rot_z,0.0,0.0,1.0); // Rotate on z
    glTranslatef(trans_x, trans_y, trans_z); //move screen horizontally, vertically, and zoom.

    LookAt(eye_x, eye_y, eye_z, target_x, target_y, target_z, up_x, up_y, up_z);
}

////////////////////////////////////////////////////////////////////////////////////
void DKFrameBase::Perspective(double fovy, double aspect, double zNear, double zFar)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double xmin, xmax, ymin, ymax;
	ymax = zNear * tan(fovy * M_PI / 360.0);
	ymin = -ymax;
	xmin = ymin * aspect;
	xmax = ymax * aspect;

#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
#endif
#if defined (ANDROID) || (IOS)
	glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);
#endif

	glMatrixMode(GL_MODELVIEW);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glDepthMask(GL_TRUE);
}

//////////////////////////////////////////////////////////////////
void DKFrameBase::LookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
           GLfloat centerx, GLfloat centery, GLfloat centerz,
           GLfloat upx, GLfloat upy, GLfloat upz)
 {
    GLfloat m[16];
    GLfloat x[3], y[3], z[3];
    GLfloat mag;

    // Make rotation matrix

    // Z vector
    z[0] = eyex - centerx;
    z[1] = eyey - centery;
    z[2] = eyez - centerz;

    mag = sqrt(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);

    if (mag) {                   // mpichler, 19950515
       z[0] /= mag;
       z[1] /= mag;
       z[2] /= mag;
    }

    // Y vector
    y[0] = upx;
    y[1] = upy;
    y[2] = upz;

    // X vector = Y cross Z
    x[0] = y[1] * z[2] - y[2] * z[1];
    x[1] = -y[0] * z[2] + y[2] * z[0];
    x[2] = y[0] * z[1] - y[1] * z[0];

    // Recompute Y = Z cross X
    y[0] = z[1] * x[2] - z[2] * x[1];
    y[1] = -z[0] * x[2] + z[2] * x[0];
    y[2] = z[0] * x[1] - z[1] * x[0];

    mag = sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);

    if (mag) {
       x[0] /= mag;
       x[1] /= mag;
       x[2] /= mag;
    }
    mag = sqrt(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);

    if (mag) {
       y[0] /= mag;
       y[1] /= mag;
       y[2] /= mag;
    }

 #define M(row,col)  m[col*4+row]

    M(0, 0) = x[0];
    M(0, 1) = x[1];
    M(0, 2) = x[2];
    M(0, 3) = 0.0;
    M(1, 0) = y[0];
    M(1, 1) = y[1];
    M(1, 2) = y[2];
    M(1, 3) = 0.0;
    M(2, 0) = z[0];
    M(2, 1) = z[1];
    M(2, 2) = z[2];
    M(2, 3) = 0.0;
    M(3, 0) = 0.0;
    M(3, 1) = 0.0;
    M(3, 2) = 0.0;
    M(3, 3) = 1.0;

 #undef M

    glMultMatrixf(m);
    glTranslatef(-eyex, -eyey, -eyez); // Translate Eye to Origin
}