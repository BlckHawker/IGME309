#include "AppClass.h"
std::vector<MyMesh*> cubeList;
float x = 0;
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	m_pMesh = new MyMesh();

	int cubeCount = 46;
	for (int i = 0; i < cubeCount; i++)
	{
		MyMesh* mesh = new MyMesh();
		cubeList.push_back(mesh);
		cubeList[i]->GenerateCube(1.0f, C_BLACK);
	}	
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	float velocity = 0.01f;

	x += velocity;

	float newY = glm::sin(x);

	
	//row 1
	cubeList[0]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, 4 + newY, 0)));

	
	cubeList[1]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, 4 + newY, 0)));

	//row 2
	cubeList[2]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-2 + x, 3 + newY, 0)));
	cubeList[3]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(2 + x, 3 + newY, 0)));

	//row 3
	cubeList[4]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, 2 + newY, 0)));
	cubeList[5]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-2 + x, 2 + newY, 0)));
	cubeList[6]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-1 + x, 2 + newY, 0)));
	cubeList[7]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(0 + x, 2 + newY, 0)));
	cubeList[8]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(1 + x, 2 + newY, 0)));
	cubeList[9]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(2 + x, 2 + newY, 0)));
	cubeList[10]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, 2 + newY, 0)));
	//row 4
	cubeList[11]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-4 + x, 1 + newY, 0)));
	cubeList[12]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, 1 + newY, 0)));
	cubeList[13]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-1 + x, 1 + newY, 0)));
	cubeList[14]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(0 + x, 1 + newY, 0)));
	cubeList[15]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(1 + x, 1 + newY, 0)));
	cubeList[16]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, 1 + newY, 0)));
	cubeList[17]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(4 + x, 1 + newY, 0)));

	//row 5
	cubeList[18]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-5 + x, 0 + newY, 0)));
	cubeList[19]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-4 + x, 0 + newY, 0)));
	cubeList[20]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, 0 + newY, 0)));
	cubeList[21]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-2 + x, 0 + newY, 0)));
	cubeList[22]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-1 + x, 0 + newY, 0)));
	cubeList[23]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(x, newY, 0)));
	cubeList[24]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(1 + x, 0 + newY,0)));
	cubeList[25]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(2 + x, 0 + newY, 0)));
	cubeList[26]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, 0 + newY, 0)));
	cubeList[27]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(4 + x, 0 + newY, 0)));
	cubeList[28]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(5 + x, 0 + newY, 0)));

	//row 6
	cubeList[29]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-5 + x, -1 + newY, 0)));
	cubeList[30]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, -1 + newY, 0)));
	cubeList[31]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-2 + x, -1 + newY, 0)));
	cubeList[32]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-1 + x, -1 + newY, 0)));
	cubeList[33]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(0 + x, -1 + newY, 0)));
	cubeList[34]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(1 + x, -1 + newY, 0)));
	cubeList[35]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(2 + x, -1 + newY, 0)));
	cubeList[36]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, -1 + newY, 0)));
	cubeList[37]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(5 + x, -1 + newY, 0)));

	//row 7
	cubeList[38]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-5 + x, -2 + newY, 0)));
	cubeList[39]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-3 + x, -2 + newY, 0)));
	cubeList[40]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(3 + x, -2 + newY, 0)));
	cubeList[41]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(5 + x, -2 + newY, 0)));

	//row 8
	cubeList[41]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-2 + x, -3 + newY, 0)));
	cubeList[41]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(-1 + x, -3 + newY, 0)));
	cubeList[41]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(1 + x, -3 + newY, 0)));
	cubeList[41]->Render(m4Projection, m4View, glm::translate(IDENTITY_M4, vector3(2 + x, -3 + newY, 0)));

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}
