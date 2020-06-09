#ifndef __Sample_PBR_filament_H__
#define __Sample_PBR_filament_H__

#include "SdkSample.h"
#include "SamplePlugin.h"

using namespace Ogre;
using namespace OgreBites;

class _OgreSampleClassExport Sample_PBR_filament : public SdkSample
{
public:
    Sample_PBR_filament()
    {
        mInfo["Title"] = "Physically Based Rendering with filament";
        mInfo["Description"] = "Shows how to do physically based rendering using the filament shaders";
        mInfo["Thumbnail"] = "thumb_pbr.png";
        mInfo["Category"] = "Lighting";
    }

    ~Sample_PBR_filament()
    {
        
    }

protected:
    void setupContent()
    {
        mCamera->setNearClipDistance(0.1);
        mCameraMan->setStyle(CS_ORBIT);
        mCameraMan->setYawPitchDist(Degree(-30), Degree(30), 3);
        mTrayMgr->showCursor();

        Light* light = mSceneMgr->createLight();
        light->setDiffuseColour(ColourValue::White);

        mSceneMgr->getRootSceneNode()
            ->createChildSceneNode(Vector3(4, 1, 6))
            ->attachObject(light);

        Entity* ent = mSceneMgr->createEntity("DamagedHelmet", "DamagedHelmet.mesh");
        ent->getMesh()->buildTangentVectors(); // enforce that we have tangent vectors

        SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
        node->pitch(Degree(90));
        node->attachObject(ent);

        mViewport->setBackgroundColour(ColourValue(0.05, 0.05, 0.05));
    }
};

#endif
