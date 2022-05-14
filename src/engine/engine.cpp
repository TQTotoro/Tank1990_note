#include "engine.h"


Engine::Engine()
{
    m_renderer = nullptr; // 初始化
    m_sprite_config = nullptr;
}

Engine &Engine::getEngine()
{
    static Engine engine; // 创建引擎
    return engine;
}

std::string Engine::intToString(int num) // 数字转字符串
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
    m_renderer = new Renderer; // 创建渲染器
    m_sprite_config = new SpriteConfig;
}

void Engine::destroyModules()
{
    delete m_renderer; // 删除并置空
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
