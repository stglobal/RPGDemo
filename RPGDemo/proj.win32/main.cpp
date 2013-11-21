#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "Menu/MenuMain.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("RPGDemo");
    //eglView->setFrameSize(480, 320);

	eglView->setFrameSize(1280, 720);
	eglView->setFrameZoomFactor(0.7f);

	CSTObject *pMenuMain = new CMenuMain;
	int i = pMenuMain->GetClassType();
	delete pMenuMain;
    return CCApplication::sharedApplication()->run();
}
