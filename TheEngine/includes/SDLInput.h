#pragma once
#include "IInput.h"


class SDLInput final : public homer::IInput {
    public:
        SDLInput();
	
        virtual ~SDLInput() = default;

        virtual bool IsKeyDown(int key) override;
        virtual bool IsButtonDown(int button) override;
        virtual void GetMousePos(int* x, int* y) override;
private:
    const unsigned char* m_KeyStates = { 0 };
    int m_MouseX = 0;
    int m_MouseY = 0;
    bool m_MouseStates[3] = { false,false,false };
protected:
    virtual void Update() override;
};