#include "Application.h"


GLFWwindow* global_window;

float screenWidth = 800.0f;
float screenHeight = 600.0f;
bool initMouse = true;
float m_xLastPos = screenWidth / 2, m_yLastPos = screenHeight / 2;
Camera* cameraClass = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));



void framebuffer_size_callback(GLFWwindow * global_window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow * global_window, double xpos, double ypos)
{
	//xpos and ypos represent current mouse position

	if (initMouse)
	{
		m_xLastPos = xpos;
		m_yLastPos = ypos;
		initMouse = false;
	}

	float m_xOffset = xpos - m_xLastPos;
	float m_yOffset = m_yLastPos - ypos; // this has to be reversed since the y position coordinates range from bottom to top
	m_xLastPos = xpos;
	m_yLastPos = ypos;

	cameraClass->CameraMouseNavigation(m_xOffset, m_yOffset);
}

void scroll_callback(GLFWwindow * global_window, double xoffset, double yoffset)
{
	cameraClass->CameraMouseScroll(yoffset);
}

int Application::InitMain()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	global_window = glfwCreateWindow(screenWidth, screenHeight, "LearningHowToOpenGL", NULL, NULL); // initialising window parameters
	if (global_window == NULL) // errorcheck 
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(global_window);
	glfwSetFramebufferSizeCallback(global_window, framebuffer_size_callback);
	glfwSetCursorPosCallback(global_window, mouse_callback);
	glfwSetScrollCallback(global_window, scroll_callback);
	glfwSetInputMode(global_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // disables the mouse within the screen if its in the game window

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "failed to initialise GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	ShaderLoader shaderOne("VertShader.glsl", "FragShader.glsl");
	ShaderLoader shaderSun("SomeShader.glsl", "SomeFragShader.glsl");
	ShaderLoader shaderSun2("SomeShader.glsl", "SomeFragShader.glsl");

	std::shared_ptr<GameObject> m_gameObject = GameObject::create();
	std::shared_ptr<GameObject> m_gameObject2 = GameObject::create();
	std::shared_ptr<GameObject> m_gameObject3 = GameObject::create();
	std::shared_ptr<GameObject> m_gameObject4 = GameObject::create();
	std::shared_ptr<GameObject> m_gameObject5 = GameObject::create();

	const char * m_texturePath = "assets/container.jpg"; // texture path
	const char * m_texturePath2 = "assets/seamless_texture_5_by_agf81.jpg";

	m_gameObject->AddChildComponent<Mesh>();
	m_gameObject->GetComponent<Mesh>()->CreateCubeMesh();
	m_gameObject->AddChildComponent<Renderer>();


	m_gameObject3->AddChildComponent<Texture>();
	m_gameObject3->GetComponent<Texture>()->TextureLoader(m_texturePath2);
	m_gameObject3->GetComponent<Texture>()->SetDiffuseMap();
	m_gameObject3->AddChildComponent<Mesh>();
	m_gameObject3->GetComponent<Mesh>()->CreateCubeMesh();
	m_gameObject3->AddChildComponent<Renderer>();

	m_gameObject4->AddChildComponent<Texture>();
	m_gameObject4->GetComponent<Texture>()->TextureLoader(m_texturePath);
	m_gameObject4->GetComponent<Texture>()->SetDiffuseMap();
	m_gameObject4->AddChildComponent<Mesh>();
	m_gameObject4->GetComponent<Mesh>()->CreateCubeMesh();
	m_gameObject4->AddChildComponent<Renderer>();

	m_gameObject2->AddChildComponent<Texture>();
	m_gameObject2->GetComponent<Texture>()->TextureLoader(m_texturePath);
	m_gameObject2->GetComponent<Texture>()->SetDiffuseMap();
	m_gameObject2->AddChildComponent<Mesh>();
	m_gameObject2->GetComponent<Mesh>()->CreateCubeMesh();
	m_gameObject2->AddChildComponent<Renderer>();

	m_gameObject5->AddChildComponent<Texture>();
	m_gameObject5->GetComponent<Texture>()->TextureLoader(m_texturePath);
	m_gameObject5->GetComponent<Texture>()->SetDiffuseMap();
	m_gameObject5->AddChildComponent<Mesh>();
	m_gameObject5->GetComponent<Mesh>()->CreateCubeMesh();
	m_gameObject5->AddChildComponent<Renderer>();

	glBindBuffer(GL_ARRAY_BUFFER, m_gameObject->GetComponent<Mesh>()->GetMeshVBO());


	m_gameObject->GetComponent<Transform>()->SetPosition(glm::vec3(-10.0f, 10.0f, -10.0f));
	m_gameObject->GetComponent<Transform>()->SetRotation(10.0f);
	m_gameObject->GetComponent<Transform>()->SetScale(glm::vec3(2.0f));
	m_gameObject->GetComponent<Transform>()->SetRotationAxis(glm::vec3(1.0f, 0.3f, 0.5f));
	m_gameObject->GetComponent<Transform>()->SetModelMatrix();

	m_gameObject3->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -3.0f, 0.0f));
	m_gameObject3->GetComponent<Transform>()->SetRotation(0.0f);
	m_gameObject3->GetComponent<Transform>()->SetScale(glm::vec3(12.0f, 0.5f, 12.0f));
	m_gameObject3->GetComponent<Transform>()->SetRotationAxis(glm::vec3(1.0f, 1.0f, 1.0f));
	m_gameObject3->GetComponent<Transform>()->SetModelMatrix();

	m_gameObject4->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, -2.3f, 0.0f));
	m_gameObject4->GetComponent<Transform>()->SetRotation(0.0f);
	m_gameObject4->GetComponent<Transform>()->SetScale(glm::vec3(1.0f));
	m_gameObject4->GetComponent<Transform>()->SetRotationAxis(glm::vec3(1.0f, 1.0f, 1.0f));
	m_gameObject4->GetComponent<Transform>()->SetModelMatrix();

	m_gameObject2->GetComponent<Transform>()->SetPosition(glm::vec3(2.0f, -2.3f, 0.0f));
	m_gameObject2->GetComponent<Transform>()->SetRotation(0.0f);
	m_gameObject2->GetComponent<Transform>()->SetScale(glm::vec3(1.0f));
	m_gameObject2->GetComponent<Transform>()->SetRotationAxis(glm::vec3(1.0f, 1.0f, 1.0f));
	m_gameObject2->GetComponent<Transform>()->SetModelMatrix();

	m_gameObject5->GetComponent<Transform>()->SetPosition(glm::vec3(4.0f, -2.3f, -2.0f));
	m_gameObject5->GetComponent<Transform>()->SetRotation(0.0f);
	m_gameObject5->GetComponent<Transform>()->SetScale(glm::vec3(1.0f));
	m_gameObject5->GetComponent<Transform>()->SetRotationAxis(glm::vec3(1.0f, 1.0f, 1.0f));
	m_gameObject5->GetComponent<Transform>()->SetModelMatrix();



	m_gameObject3->GetComponent<Renderer>()->SetLightPosition(m_gameObject->GetComponent<Transform>()->GetPosition());
	m_gameObject4->GetComponent<Renderer>()->SetLightPosition(m_gameObject->GetComponent<Transform>()->GetPosition());
	m_gameObject2->GetComponent<Renderer>()->SetLightPosition(m_gameObject->GetComponent<Transform>()->GetPosition());
	m_gameObject5->GetComponent<Renderer>()->SetLightPosition(m_gameObject->GetComponent<Transform>()->GetPosition());

	m_gameObject->GetComponent<Renderer>()->SetShader(shaderSun);
	m_gameObject3->GetComponent<Renderer>()->SetShader(shaderOne);
	m_gameObject4->GetComponent<Renderer>()->SetShader(shaderOne);
	m_gameObject2->GetComponent<Renderer>()->SetShader(shaderOne);
	m_gameObject5->GetComponent<Renderer>()->SetShader(shaderOne);

	listOfGameObjects.push_back(m_gameObject);
	listOfGameObjects.push_back(m_gameObject2);
	listOfGameObjects.push_back(m_gameObject3);
	listOfGameObjects.push_back(m_gameObject4);
	listOfGameObjects.push_back(m_gameObject5);
	
	Update();

	glDeleteVertexArrays(1, m_gameObject5->GetComponent<Mesh>()->GetMeshVAOPointer());
	glDeleteVertexArrays(1, m_gameObject4->GetComponent<Mesh>()->GetMeshVAOPointer());
	glDeleteVertexArrays(1, m_gameObject3->GetComponent<Mesh>()->GetMeshVAOPointer());
	glDeleteVertexArrays(1, m_gameObject2->GetComponent<Mesh>()->GetMeshVAOPointer());
	glDeleteVertexArrays(1, m_gameObject->GetComponent<Mesh>()->GetMeshVAOPointer());
	glDeleteBuffers(1, m_gameObject->GetComponent<Mesh>()->GetMeshVBOPointer());

	glfwTerminate();
	return 0;
}



void Application::Update()
{


	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	while (!glfwWindowShouldClose(global_window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		inputClass->ProcessInput();
		cameraClass->Update(deltaTime);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear the colour to gray blue ish
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (int i = 0; i < listOfGameObjects.size(); i++)
		{
			if (listOfGameObjects.at(i)->GetComponent<Texture>() != NULL)
			{
				listOfGameObjects.at(i)->GetComponent<Renderer>()->Render(cameraClass, listOfGameObjects.at(i)->GetComponent<Transform>(), 
					listOfGameObjects.at(i)->GetComponent<Mesh>(), listOfGameObjects.at(i)->GetComponent<Texture>());
			}
			else
			{
				listOfGameObjects.at(i)->GetComponent<Renderer>()->Render(cameraClass, listOfGameObjects.at(i)->GetComponent<Transform>(), 
					listOfGameObjects.at(i)->GetComponent<Mesh>());

			}
		}

		glfwSwapBuffers(global_window); // swap front and back buffers
		glfwPollEvents(); // check events



	}
}

Application::Application()
{
}


Application::~Application()
{
}
