#include <ctime>

#include "CMobile.h"

CMobile::CMobile(const char* strTexturePath, sf::Vector2f vecSpeed, sf::IntRect rBounds):
    m_texture(),
    m_vecSpeed(vecSpeed),
    m_rBounds(rBounds),
    m_cHue(0xFFFFFFFF),
    m_colorStatus(ST_WHITE)
{
    srand((unsigned int)time(nullptr));

    m_texture.loadFromFile(strTexturePath);
    setTexture(m_texture);
    setPosition(
        m_rBounds.left+rand()%(int)(rBounds.width-getLocalBounds().width),
        m_rBounds.top+rand()%(int)(rBounds.height-getLocalBounds().height)
    );
}

CMobile::~CMobile(){}

void CMobile::Animate(float dt){

    if(getPosition().x<=m_rBounds.left ||getLocalBounds().width+getPosition().x>=m_rBounds.left+m_rBounds.width){
        m_vecSpeed.x*=-1;
        setColor(sf::Color(100+rand()%156, 100+rand()%156, 100+rand()%156, 255));
    }
    if(getPosition().y<=m_rBounds.top ||getLocalBounds().height+getPosition().y>=m_rBounds.top+m_rBounds.height){
        m_vecSpeed.y*=-1;
        setColor(sf::Color(100+rand()%156, 100+rand()%156, 100+rand()%156, 255));
    }
    move(m_vecSpeed.x*dt, m_vecSpeed.y*dt);
}