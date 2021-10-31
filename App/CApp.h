#include <SFML/Graphics.hpp>

#include <CMobile.h>

#define     APP_MOBILE_IMAGE_PATH       "Resources/dvd.png"
#define     APP_FONT_PATH               "Resources/segoeui.ttf"

class CApp{
private:
    const char*     m_strTitle;
    int    m_iWidth, m_iHeight;
    sf::RenderWindow  m_window;
    int              m_uStatus;
    CMobile*         m_pMobile;
    sf::Font            m_font;
    sf::Text   m_textFrametime;
private:
    enum e_status{
        ST_ALL_CLEARED          = 0x0,
        ST_SFML_INITIATED       = 0x1,
        ST_FRAME_INFO_SHOWN     = 0x800,
        ST_FRAME_INFO_SWITCH    = 0x8000
    };

    CApp(); 

    /*
     * We're making the default constructor 
     * private here so the end developer is 
     * forced to use the overloaded one
    */
   
public:
    CApp(int iWidth, int iHeight, const char *strTitle, sf::Int32 flags);
    ~CApp();
    void Run();
};