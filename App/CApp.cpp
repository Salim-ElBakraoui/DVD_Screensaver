#include <iostream>
using namespace std;

#include <cstdio>

#include <macros.h>

#include "CApp.h"

CApp::CApp(int iWidth, int iHeight, const char *strTitle, sf::Int32 flags):
    m_strTitle(strTitle),
    m_iWidth(iWidth), m_iHeight(iHeight),
    m_window(sf::VideoMode(m_iWidth, m_iHeight), m_strTitle, flags),
    m_uStatus(ST_ALL_CLEARED),
    m_pMobile(new CMobile(APP_MOBILE_IMAGE_PATH, sf::Vector2f{100,100}, sf::IntRect{0,0,m_iWidth, m_iHeight})),
    m_font(),
    m_textFrametime()
{
    if(m_window.isOpen())
        mBitsSet(m_uStatus, ST_SFML_INITIATED);

    m_font.loadFromFile(APP_FONT_PATH);
    m_textFrametime.setFont(m_font);
    m_textFrametime.setCharacterSize(16);
    m_textFrametime.setFillColor(sf::Color::White);

    Run();
}

CApp::~CApp(){
    delete m_pMobile;
}

void CApp::Run(){
    m_window.setFramerateLimit(144);

    if(mIsBitsClr(m_uStatus, ST_SFML_INITIATED)){
        cerr << "SFML wasn't initialized correctly, aborting." << endl;
        return;
    }

    sf::Event event;
    sf::Clock clock;

    char buf[32];

    while(m_window.isOpen()){

        float dt = clock.restart().asSeconds();
        
        while(m_window.pollEvent(event)){
            
            if(event.type == sf::Event::Closed)
                m_window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape)
                    m_window.close();
                
                if(event.key.code == sf::Keyboard::F1)
                    mBitsTgl(m_uStatus, ST_FRAME_INFO_SWITCH);

                if(event.key.code == sf::Keyboard::F2)
                    mBitsTgl(m_uStatus, ST_FRAME_INFO_SHOWN);
            }
        }

        if(mIsBitsSet(m_uStatus, ST_FRAME_INFO_SWITCH)){
            sprintf(buf, "FPS : %.0f", 1/dt);
            m_textFrametime.setString(buf);
        }
        else{
            sprintf(buf, "Frametime : %.6f", dt);
            m_textFrametime.setString(buf);
        }

        m_pMobile->Animate(dt);        

        m_window.clear(sf::Color{0x000000FF});
        m_window.draw(*m_pMobile);

        if(mIsBitsSet(m_uStatus, ST_FRAME_INFO_SHOWN))
            m_window.draw(m_textFrametime);
        
        m_window.display();
    }
}