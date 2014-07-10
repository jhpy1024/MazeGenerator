#ifndef SAVE_FILE_OVERLAY_HPP
#define SAVE_FILE_OVERLAY_HPP

#include <SFML/Graphics.hpp>

class SaveFileOverlay : public sf::Drawable
{
public:
    SaveFileOverlay();

    void create(int width, int height);
    void show();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    void update() const;
    void createShape();
    
private:
    int m_Width;
    int m_Height;

    sf::Clock m_Clock;
    sf::Time m_SaveTime;
    const sf::Time TIME_VISIBLE;
    mutable bool m_IsVisible;

    sf::RectangleShape m_Shape;
    sf::Texture m_Texture;
};

#endif

