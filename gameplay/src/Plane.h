/*
 * Plane.h
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Matrix.h"

namespace gameplay
{

class BoundingSphere;
class BoundingBox;
class Frustum;
class Ray;

/**
 * Defines a plane.
 *
 * The plane is represented as a plane using a 3D vector normal and a
 * distance value (stored as a negative value).
 */
class Plane
{
public:

    /**
     * Represents when a 3D entity intersects a plane.
     */
    static const int INTERSECTS_INTERSECTING = 0;

    /**
     * Represents when a 3D entity is in front of (in the positive half-space of) a plane.
     */
    static const int INTERSECTS_FRONT = 1;

    /**
     * Represents when a 3D entity is behind (in the negative half-space of) a plane.
     */
    static const int INTERSECTS_BACK = -1;

    /**
     * Constructor.
     */
    Plane();

    /**
     * Constructs a new plane from the specified values.
     *
     * @param normal The normal vector of this plane.
     * @param distance The distance to this plane along its (unit) normal to the origin.
     */
    Plane(const Vector3& normal, float distance);

    /**
     * Constructs a new plane from the given plane.
     *
     * @param copy The plane to copy.
     */
    Plane(const Plane& copy);

    /**
     * Destructor.
     */
    ~Plane();

    /**
     * Gets the plane's normal in the given vector.
     *
     * @return normal The plane's normal.
     */
    const Vector3& getNormal() const;

    /**
     * Sets the plane's normal to the given vector.
     *
     * @param normal The new normal vector.
     */
    void setNormal(const Vector3& normal);

    /**
     * Gets the plane's distance to the origin along its normal.
     *
     * @return The plane's distance to the origin along its normal.
     */
    float getDistance() const;

    /**
     * Sets the plane's distance to the origin along its normal.
     *
     * @param distance The new distance.
     */
    void setDistance(float distance);

    /**
     * Calculates the distance from this plane to the specified point.
     *
     * @param point The point to calculate distance to.
     */
    float distance(const Vector3& point) const;

    /**
     * Calculates the point of intersection of the given three planes and stores it in the given point.
     *
     * @param p1 The first plane.
     * @param p2 The second plane.
     * @param p3 The third plane.
     * @param point The point to store the point of intersection in
     *  (this is left unmodified if the planes do not all intersect or if
     *  they are all parallel along one vector and intersect along a line).
     */
    static void intersection(const Plane& p1, const Plane& p2, const Plane& p3, Vector3* point);

    /**
     * Tests whether this plane intersects the specified bounding sphere.
     *
     * @param sphere The bounding sphere to test intersection with.
     * 
     * @return Plane::INTERSECTS_BACK if the specified bounding object is in the negative half-space of
     *  this plane, Plane::INTERSECTS_FRONT if it is in the positive half-space of this plane,
     *  and Plane::INTERSECTS_INTERSECTING if it intersects this plane.
     */
    float intersects(const BoundingSphere& sphere) const;

    /**
     * Tests whether this plane intersects the specified bounding box.
     *
     * @param box The bounding box to test intersection with.
     * 
     * @return Plane::INTERSECTS_BACK if the specified bounding object is in the negative half-space of
     *  this plane, Plane::INTERSECTS_FRONT if it is in the positive half-space of this plane,
     *  and Plane::INTERSECTS_INTERSECTING if it intersects this plane.
     */
    float intersects(const BoundingBox& box) const;

    /**
     * Tests whether this plane intersects the specified frustum.
     *
     * @param frustum The frustum to test intersection with.
     * 
     * @return Plane::INTERSECTS_BACK if the specified frustum is in the negative half-space of
     *  this plane, Plane::INTERSECTS_FRONT if it is in the positive half-space of this plane,
     *  and Plane::INTERSECTS_INTERSECTING if it intersects this plane.
     */
    float intersects(const Frustum& frustum) const;

    /**
     * Tests whether this plane intersects the specified plane.
     *
     * @param plane The plane to test intersection with.
     * 
     * @return Plane::INTERSECTS_BACK if the specified plane is in the negative half-space of
     *  this plane, Plane::INTERSECTS_FRONT if it is in the positive half-space of this plane,
     *  and Plane::INTERSECTS_INTERSECTING if it intersects this plane.
     */
    float intersects(const Plane& plane) const;

    /**
     * Tests whether this plane intersects the specified ray.
     *
     * @param ray The ray to test intersection with.
     * 
     * @return Plane::INTERSECTS_BACK if the specified ray is in the negative half-space of
     *  this plane, Plane::INTERSECTS_FRONT if it is in the positive half-space of this plane,
     *  and Plane::INTERSECTS_INTERSECTING if it intersects this plane.
     */
    float intersects(const Ray& ray) const;

    /**
     * Determines whether the given plane is parallel to this plane.
     * 
     * @param plane The plane to test.
     * 
     * @return true if the given plane is parallel to this plane; false otherwise.
     */
    bool isParallel(const Plane& plane) const;

    /**
     * Sets this plane to the specified values.
     *
     * @param normal The normal vector of this plane.
     * @param distance The distance to this plane along its normal to the origin.
     */
    void set(const Vector3& normal, float distance);

    /**
     * Sets this plane to the given plane.
     *
     * @param plane The plane to copy.
     */
    void set(const Plane& plane);

    /**
     * Transforms this plane by the given transformation matrix.
     *
     * @param matrix The transformation matrix to transform by.
     */
    void transform(Matrix& matrix);

private:

    /**
     * Normalizes this plane.
     */
    void normalize();

    Vector3 _normal;    // The normal vector of the Plane.
    float _distance;    // The distance of the Plane along its normal from the origin.
};

}

#endif