#include <SFML/Graphics.hpp>

class CMobile : public sf::Sprite{
private:
    sf::Texture     m_texture;
    sf::Vector2f    m_vecSpeed;
    sf::IntRect     m_rBounds;
    sf::Color       m_cHue;
    unsigned int    m_colorStatus;
private:
    enum e_colorStatus{
        ST_WHITE     = 0x0,
        ST_RED,
        ST_ORANGE,
        ST_YELLOW,
        ST_GREEN,
        ST_BLUE,
        ST_INDIGO,
        ST_PURPLE
    };
private:
    CMobile();

public:
    CMobile(const char* strTexturePath, sf::Vector2f vecSpeed, sf::IntRect rBounds);
    ~CMobile();
    void Animate(float dt);

};