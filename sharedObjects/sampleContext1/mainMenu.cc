#include "../interfaceHeaders.h"
class MainMenu : public ContextInterface{
	private:
		const int id = 0;
		Menu2D menu;
		MorningText textObject;
		MorningButton buttonObject;

		void processInput(GLFWwindow *window){
                        //if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                        //        glfwSetWindowShouldClose(window, true);

                        if (glfwGetKey(window, GLFW_KEY_W)){
                                this->ges.keyboard.key_w = true;
                        }else{
                                this->ges.keyboard.key_w = false;
                        }

                        if (glfwGetKey(window, GLFW_KEY_S))
                                this->ges.keyboard.key_s = true;
                        else
                                this->ges.keyboard.key_s = false;

                        if (glfwGetKey(window, GLFW_KEY_A))
                                this->ges.keyboard.key_a = true;
                        else
                                this->ges.keyboard.key_a = false;

                        if (glfwGetKey(window, GLFW_KEY_D))
                                this->ges.keyboard.key_d = true;
                        else
                                this->ges.keyboard.key_d = false;

                        if(glfwGetKey(window, GLFW_KEY_SPACE)){
                                this->ges.keyboard.key_space = true;
                                this->context = 1;
                        }else{
                                this->ges.keyboard.key_space = false;
                        }

                        if(buttonObject.isHovered() && this->ges.mouse.click_left){
                                printf("Clicked Button 0\n");
                                glfwSetWindowShouldClose(window, true);
                        }

                        btn = this->menu.getButtonX(1);
                        if(btn.isHovered() && this->ges.mouse.click_left){
                                printf("Clicked Button 1\n");
                                this->context = 1;
                        }

                }


	public:
		virtual void destroy() override{
			menu.destroy();
		}
        	virtual void init() override{
                        menu.setTextureFile("./Custom/images/GameMenuTexture.jpeg");
                        menu.setVertexShaderFile("./core/2D/menu/menu.vs");
                        menu.setFragmentShaderFile("./core/2D/menu/menu.fs");

                       
                        buttonObject.name = "Red Button";
                        buttonObject.setPos(0, 0, 0.0);
                        buttonObject.setSize(0.1, 0.1, 0.1);
                        buttonObject.setColor(1.0f, 0.2f, 0.2f);
			for(int i=0; i<buttonObject.vtex_size; i++){
				buttonObject.fillMasterPosition(glm::vec3(0.0f, 0.0f, 0.0f), &buttonObject.vtex[i]);
			}

			buttonObject.fillMasterPosition(glm::vec3(0.0f, 0.0f, 0.0f), &buttonObject.vtex[0]);
			buttonObject.fillMasterPosition(glm::vec3(0.5f, 0.0f, 0.0f), &buttonObject.vtex[1]);
			buttonObject.fillMasterPosition(glm::vec3(0.25f, 0.5f, 0.0f), &buttonObject.vtex[2]);
	
			buttonObject.create();
                        //menu.addButton(0, button);


			if(!menu.create()){
                                printf("Failed to create 2D menu.\n");
                        }

                        //this->activeCamera = &menu.camera;
			this->context = 0;
		}
        	virtual int exec(GLFWwindow* window) override{
			this->processInput(window);
			menu.ges = this->ges;
                        menu.draw();
			buttonObject.ges = this->ges;
			buttonObject.draw();
			return context;
		}
};

extern "C" {
	MainMenu *create(){
		return new MainMenu;
	}
}
