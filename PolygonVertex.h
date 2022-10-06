#pragma once
#include "GameObject.h"
#include "MyMath.h"
class PolygonVertex :
    public GameObject
{

public:
    enum State {
        kMove,
        kStay,

        kStateNum
    };

    struct Data {
        Vector2D mPosition;
        float mTheta;
        State mState;
    };

private:
    Data mData;

public:
    PolygonVertex(class Game* game = nullptr);
    ~PolygonVertex();

    void Create(int i);
    void Update();

    const Vector2D& position() const { return mData.mPosition; }
};

