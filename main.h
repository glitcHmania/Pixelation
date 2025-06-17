#pragma once
#include "Game.h"
#include "UIObject.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"
#include "FpsCounter.h"
#include "FiniteMap.h"

int Setup();

int main()
{
    try
    {
        Game game({ 800u,600u });
        Renderer::CreateCamera();
        AssetLoader::LoadFromDir("Assets/");
        Setup();

        game.Loop();
        return 0;
    }
    catch (const std::exception&)
    {

    }
}

