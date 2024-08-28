#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <SDL2/SDL_video.h>
#include <assert.h>
#include <cstdlib>
#include <unistd.h>

void MonAffichageEnBoucle(SDL_Window *Window);

int main(int argc, char *argv[])
{
  int WindowFlags = SDL_WINDOW_OPENGL;
  int height = 600;
  int width = 800;
  SDL_Window *Window = SDL_CreateWindow("OpenGL Test", 0, 0, width, height, WindowFlags);
  assert(Window);
  SDL_GLContext Context = SDL_GL_CreateContext(Window);
  
  int Running = 1;
  int FullScreen = 0;
  while (Running)
  {
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
      if (Event.type == SDL_KEYDOWN)
      {
        switch (Event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            Running = 0;
            break;
          case 'f':
            FullScreen = !FullScreen;
            if (FullScreen)
            {
              SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
            }
            else
            {
              SDL_SetWindowFullscreen(Window, WindowFlags);
            }
            break;
          default:
            break;
        }
      }
      else if (Event.type == SDL_QUIT)
      {
        Running = 0;
      }
    }

    glViewport(0, 0, width, height);
    /* glClearColor(1.f, 1.f, 1.f, 0.f);*/
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(Window);

    MonAffichageEnBoucle(Window);

  }
  return EXIT_SUCCESS; 
}

float theta = 0.0;

void MonAffichageEnBoucle(SDL_Window *Window)
{
  /* OpenGL animation code goes here */
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glOrtho (-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glRotatef(theta, 0.1f, 0.1f, 0.0f);
  glPointSize(10);
  glBegin(GL_POINTS);
  glColor3f (1.0f, 0.0f, 0.0f);
  glVertex3f (-0.5, -0.5, 0.5);
  glVertex3f (0.5, -0.5, 0.5);
  glVertex3f (-0.5, 0.5, 0.5);
  glVertex3f (0.5, 0.5, 0.5);
  glVertex3f (-0.5, 0.5, -0.5);
  glVertex3f (0.5, 0.5, -0.5);
  glVertex3f (-0.5, -0.5, -0.5);
  glVertex3f (0.5, -0.5, -0.5);
  glEnd();
  glPopMatrix();
  SDL_GL_SwapWindow(Window);
  theta += 1.0f;
  /*sleep (1);*/
} 

