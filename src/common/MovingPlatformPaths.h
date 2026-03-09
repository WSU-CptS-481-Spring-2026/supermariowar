#pragma once

#include "math/Vec2.h"
#include <array>

class MovingPlatform;


/// Type ID used by the map files as a numeric identifier.
enum class PlatformPathType: unsigned char {
    Straight,
    StraightContinuous,
    Ellipse,
    Falling,
};


class MovingPlatformPath {
public:
    MovingPlatformPath(float speed, Vec2f startPos, Vec2f endPos, bool preview);
    virtual ~MovingPlatformPath() = default;

    virtual PlatformPathType typeId() const = 0;
    virtual bool Move(short type) = 0;
    virtual void Reset();

    void SetPlatform(MovingPlatform* platform) {
        m_platform = platform;
    }

    float speed() const { return m_speed; }
    const Vec2f& currentPos0() const { return m_currentPos[0]; }
    const Vec2f& currentPos1() const { return m_currentPos[1]; }
    const Vec2f& velocity0() const { return m_velocity[0]; }

protected:
    MovingPlatform* m_platform = nullptr;

    Vec2f m_startPos;
    Vec2f m_endPos;
    float m_speed;

    std::array<Vec2f, 2> m_velocity;
    std::array<Vec2f, 2> m_currentPos;
};


class StraightPath : public MovingPlatformPath {
public:
    StraightPath(float speed, Vec2f startPos, Vec2f endPos, bool preview);

    PlatformPathType typeId() const override { return PlatformPathType::Straight; }
    bool Move(short type) override;
    void Reset() override;

    const Vec2f& startPos() const { return m_startPos; }
    const Vec2f& endPos() const { return m_endPos; }

private:
    void SetVelocity(short type);

    float m_angle;
    short m_steps;

    std::array<unsigned short, 2> m_currentStep {0, 0};
    std::array<Vec2f*, 2> m_goalPoint {&m_startPos, &m_startPos};
};


class StraightPathContinuous : public MovingPlatformPath {
public:
    StraightPathContinuous(float speed, Vec2f startPos, float angle, bool preview);

    PlatformPathType typeId() const override { return PlatformPathType::StraightContinuous; }
    bool Move(short type) override;
    void Reset() override;

    const Vec2f& startPos() const { return m_startPos; }
    const Vec2f& endPos() const { return m_endPos; }
    float angle() const { return m_angle; }

private:
    void SetVelocity(short type);

    float m_angle;
    short m_steps;
    Vec2f m_edge;

    std::array<unsigned short, 2> m_currentStep {0, 0};
    std::array<Vec2f*, 2> m_goalPoint {&m_startPos, &m_startPos};
};


class EllipsePath : public MovingPlatformPath {
public:
    EllipsePath(float speed, float dAngle, Vec2f radius, Vec2f centerPos, bool preview);

    PlatformPathType typeId() const override { return PlatformPathType::Ellipse; }
    bool Move(short type) override;
    void SetPosition(short type);
    void Reset() override;

    const Vec2f& centerPos() const { return m_startPos; }
    const Vec2f& radius() const { return m_radius; }
    float startAngle() const { return m_startAngle; }

private:
    Vec2f m_radius;
    float m_startAngle;

    std::array<float, 2> m_angle;
};


class FallingPath : public MovingPlatformPath {
public:
    FallingPath(Vec2f startPos);

    PlatformPathType typeId() const override { return PlatformPathType::Falling; }
    bool Move(short type) override;
    void Reset() override;
};
