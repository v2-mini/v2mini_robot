#ifndef __ROBOT_CONTROLLER_H
#define __ROBOT_CONTROLLER_H

#include <SDL2/SDL.h>

namespace v2mini_teleop {

const int SCREEN_WIDTH = 280;
const int SCREEN_HEIGHT = 200;

const int MAX_BASE_RADIAL_VEL = 30;		// cm/s
const int MAX_BASE_ANGULAR_VEL = 80;	// deg/s
const int MAX_HEADTILT_VEL = 10;
const int MAX_HEADPAN_VEL = 10;
const int MAX_GRIPPER_VEL = 10;
const float MAX_TORSO_VEL = 1.2;
const double MAX_ARM_JOINT_VEL = M_PI/180;

enum ROBOT_VEL {
	BASE_VELX,
	BASE_VELY,
	BASE_VELZ,
	TORSO_VEL,
	FACE_TOGGLE,
	HEADTILT_VEL,
	HEADPAN_VEL,
	GRIPPER_VEL,
	ARM_JOINT_VEL,
	ARM_JOINT_TOGGLE
};

class TeleopController {

	private:

		bool quit = false;

		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture = NULL;
		SDL_GameController *controller = NULL;

		void loadGamepad();

	public:

		TeleopController();
		~TeleopController();

		float* getKeyCmds();
		float* getGamepadCmds();
		bool checkQuitStatus();
		void reRenderImage();
		void mapVelocity(float*, int);

};

}

#endif
