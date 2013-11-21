#include "MenuMain.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class UIMyTextButton:public UITextButton
{
private:
	int r,g,b;
public:
	UIMyTextButton()
	{
		r = g = b = 0;
	}
	virtual void onPressStateChangedToNormal()
	{
		this->setTextColor(255,0,0);
	}
    virtual void onPressStateChangedToPressed()
	{
		this->setTextColor(255,0,0);
	}
};

CMenuMain::CMenuMain(void)
{
	GetController()->GetInfo();
}


CMenuMain::~CMenuMain(void)
{
}

bool CMenuMain::init()
{
	if ( !CCScene::init() )
    {
        return false;
    }

	 UILayer *layer = UILayer::create();
	 this->addChild(layer);

	UIWidget* menu_root = CCUIHELPER->createWidgetFromJsonFile("MainMenu/MainMenu.json");
   // menu_root->setWidgetTag(EXAMPLE_PANEL_TAG_ROOT);
    layer->addWidget(menu_root);

	UILabel* lbl_qihuandamaoxian = dynamic_cast<UILabel*>(menu_root->getChildByName("lbl_qihuandamaoxian"));
	//UILabel* lbl_qihuandamaoxian2 = dynamic_cast<UILabel*>(layer->getWidgetByName("lbl_qihuandamaoxian"));
	lbl_qihuandamaoxian->setScaleX(7.0);

	UIMyTextButton* TextButton_start = dynamic_cast<UITextButton*>(menu_root->getChildByName("TextButton_start"));
	TextButton_start->addReleaseEvent(this, coco_releaseselector(CMenuMain::StartGame));
	return true;

}
 
void CMenuMain::StartGame(CCObject* pSender)
{    
	UITextButton* TextButton_start = dynamic_cast<UITextButton*>(pSender);
	TextButton_start->setText("aaaaaaaaaa");
    //// examples root
    //UIWidget* example_root = dynamic_cast<UIPanel*>(m_pUILayer->getWidgetByTag(EXAMPLE_PANEL_TAG_ROOT));
    //
    //// equip
    //UIPanel* equip_root = dynamic_cast<UIPanel*>(example_root->getChildByName("equip_root"));
    //equip_root->setVisible(true);
    //
    //// button panel
    //UIPanel* button_panel = dynamic_cast<UIPanel*>(example_root->getChildByName("button_panel"));
    //button_panel->disable(true);
}