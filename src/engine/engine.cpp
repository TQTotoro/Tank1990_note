#include "engine.h"


Engine::Engine()
{
    m_renderer = nullptr; // ��ʼ��
    m_sprite_config = nullptr;
}

Engine &Engine::getEngine()
{
    static Engine engine; // ��������
    return engine;
}

std::string Engine::intToString(int num) // ����ת�ַ���
{
    if(num == 0) return "0";

    std::string buf;
    bool negative = false;
    if(num < 0)
    {
        negative = true;
        num = -num;
    }
    for(; num; num /= 10) buf = "0123456789abcdef"[num % 10] + buf;
    if(negative) buf = "-" + buf;
    return buf;
}

void Engine::initModules()
{
    m_renderer = new Renderer; // ������Ⱦ��
    m_sprite_config = new SpriteConfig;
}

void Engine::destroyModules()
{
    delete m_renderer; // ɾ�����ÿ�
    m_renderer = nullptr;
    delete m_sprite_config;
    m_sprite_config = nullptr;
}

Renderer *Engine::getRenderer() const
{
    return m_renderer;
}

SpriteConfig *Engine::getSpriteConfig() const
{
    return m_sprite_config;
}
