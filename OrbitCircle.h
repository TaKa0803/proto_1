#pragma once
#include "GameObject.h"
#include "MyMath.h"
class OrbitCircle :
    public GameObject
{

public:
    struct Data {
        Vector2D mPosition;
        float mRadius;
    };

private:
    Data mData;

public:
    OrbitCircle(class Game* game);
    ~OrbitCircle();

    void Create();
    void Init();
    void Draw();

    const Vector2D& position() const { return mData.mPosition; }
    float radius() const { return mData.mRadius; }
};

