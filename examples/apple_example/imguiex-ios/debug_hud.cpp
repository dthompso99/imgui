//
//  debug_hud.cpp
//  imguiex

#include <stdio.h>

#include "debug_hud.h"
#include "imgui.h"

void DebugHUD_InitDefaults( DebugHUD *hud )
{
    hud->show_demo_window = true;
    hud->show_example_window = true;
    hud->rotation_speed = 15.0f;
    
    hud->cubeColor1[0] = 0.4f;
    hud->cubeColor1[1] = 0.4f;
    hud->cubeColor1[2] = 1.0f;
    hud->cubeColor1[3] = 1.0f;
    
    hud->cubeColor2[0] = 1.0f;
    hud->cubeColor2[1] = 0.4f;
    hud->cubeColor2[2] = 0.4f;
    hud->cubeColor2[3] = 1.0f;
}

void DebugHUD_DoInterface(DebugHUD *hud)
{
    if (hud->show_demo_window)
    {
        ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
        ImGui::ShowDemoWindow(&hud->show_demo_window );
    }
    
    if (hud->show_example_window)
    {
        ImGui::Begin("Another Window", &hud->show_example_window);
        ImGui::Text("Hello from another window!");
        ImGui::ColorEdit3("Cube 1 Color", hud->cubeColor1);
        ImGui::ColorEdit3("Cube 2 Color", hud->cubeColor2);
        ImGui::SliderFloat("Rotation Speed", &hud->rotation_speed, 0.0f, 200.0f);
        ImGui::End();
    }
}
