#pragma once

#ifndef _component_h_
#define _component_h_

namespace engine {
    class IComponent {
    public:
        IComponent() = default;
        IComponent(IComponent&) = delete;
        IComponent(IComponent&&) = delete;
        virtual ~IComponent() = default;
    public:
        IComponent& operator=(IComponent&) = delete;
        IComponent& operator=(IComponent&&) = delete; 
    };
}

#endif