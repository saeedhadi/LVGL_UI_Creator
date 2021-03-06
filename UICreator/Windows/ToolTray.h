#pragma once
#include <string>
#include <vector>
#include "lvgl/lvgl.h"
#include "../Widgets/TreeView.h"
#include "../Widgets/MinimizableWindow.h"
#include "../LVSerial/Serialization/ObjectUserData.h"
#include <Serialization/ObjectSerializer.h>

#pragma region Object Creation Includes
#include "../ObjectCreation/Arc.h"
#include "../ObjectCreation/Bar.h"
#include "../ObjectCreation/Button.h"
#include "../ObjectCreation/ButtonMatrix.h"
#include "../ObjectCreation/Calendar.h"
#include "../ObjectCreation/Canvas.h"
#pragma endregion
#undef GetObject

class PropertyWindow;
class ToolBar;

class ToolTray
{
public:
    ToolTray(lv_obj_t* parent,
             TreeView* objectTree,
             lv_obj_t* drawSurface,
             PropertyWindow* propWin,
             ToolBar* toolBar);

private:
    lv_obj_t* toolWin;
    ToolBar* toolBar;
    MinimizableWindow* minWin;
    TreeView* objTree;
    lv_obj_t* drawSurface;
    PropertyWindow* propertyWindow;
    void initializeToolMatrix();
    void initializeWidgetButtons(lv_obj_t* parent);
    uint16_t currentID = 0;

    std::vector<lv_obj_t*> widgetButtons;
    lv_obj_t* lastWidget = nullptr;

    struct sCB
    {
        ToolTray* toolTray;
        int typeID;
    };

#pragma region Callbacks
    static void create_obj_cb(lv_obj_t* obj, lv_event_t ev);
    static void updateProperties(lv_obj_t* obj, lv_event_t ev);
#pragma endregion
};
