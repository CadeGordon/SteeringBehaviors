#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    

    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"></param>
    void setName(const char* name) { m_name = name; }

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);


    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name="component">the new component to attack to the actor</param>
    /// <returns>A reference to the component added to the array</returns>
    template<typename T>
    T* addComponent();

    Component* addComponent(Component* component);

    /// <summary>
    /// Removes the first instacne found that matches the component reference
    /// </summary>
    /// <param name="component">The compoenet to remove from the array</param>
    /// <returns>False if the component is not in the array</returns>
    
    bool removeComponent(Component* component);


    /// <summary>
    /// Removes the first instacne found that matches the component name
    /// </summary>
    /// <param name="component">The compoenet to remove from the array</param>
    /// <returns>False if the component is not in the array</returns>
    template<typename T>
    bool removeComponent();


    /// <summary>
    /// Gets the first component instance attached to this actor 
    /// that matches the name
    /// </summary>
    /// <param name="componentName">The name of the component instance</param>
    /// <returns>the name of the component instance</returns>
    template<typename T>
    T* getComponent();


    

protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    unsigned int m_componentCount;
    Component** m_comp;
    
    
};

template<typename T>
inline T* Actor::addComponent()
{
    T* component = new T();
    //Retunr null if this compoent has an owner already
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new array with a size one greater than our old array
    Component** tempArray = new Component * [m_componentCount + 1];

    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        tempArray[i] = m_comp[i];

    }

    //Set the last value in the new array to be the actor we want to add
    tempArray[m_componentCount] = component;
    if (m_componentCount > 1)
        //set old array to hold the values of the new array
        delete[] m_comp;
    else if (m_componentCount == 1)
        delete m_comp;

    m_comp = tempArray;
    m_componentCount++;

    return (T*)component;
}

template<typename T>
inline bool Actor::removeComponent()
{
    bool componentRemoved = false;

    Component** newArray = new Component * [m_componentCount - 1];

    int j = 0;

    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_comp[i]);
        if (!temp)
        {
            newArray[j] = m_comp[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }
    
    if (componentRemoved)
    {
        //Set the old array to the new array
        m_comp = newArray;
        m_componentCount--;

    }

    //retunr whether or not the removal was successful
    return componentRemoved;
}

template<typename T>
inline T* Actor::getComponent()
{
    //Iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_comp[i]);
        //Retunr the component if the name is the same as the current component
        if (temp)
            return (T*)m_comp[i];

    }

    //Return nullptr if the compoent is not in the list
    return nullptr;
}
