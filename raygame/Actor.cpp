#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"


Actor::Actor()
{
    m_transform = new Transform2D(this);
   
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
    
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->onCollision(other);
}

Component* Actor::addComponent(Component* component)
{
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

    return component;
}

bool Actor::removeComponent(Component* component)
{
    if(!component)
    return false;

    bool componentRemoved = false;

    Component** newArray = new Component * [m_componentCount - 1];

    int j = 0;

    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_comp[i])
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
       delete component;

    }
    
    //retunr whether or not the removal was successful
    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    if (!name)
        return false;

    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    Component** newArray = new Component * [m_componentCount - 1];

    int j = 0;

    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_comp[i]->getName(), name) == 0)
        {
            newArray[j] = m_comp[i];
            j++;
        }
        else
        {
            componentRemoved = true;
            componentToDelete = m_comp[i];
        }
    }


    if (componentRemoved)
    {
        //Set the old array to the new array
        m_comp = newArray;
        m_componentCount--;
        delete componentToDelete;

    }

    delete[] newArray;

    //retunr whether or not the removal was successful
    return componentRemoved;
}

Component* Actor::getComponent(const char* componentName)
{
    //Iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        //Retunr the component if the name is the same as the current component
        if (strcmp(m_comp[i]->getName(), componentName) == 0 )
            return m_comp[i];
    }

    //Return nullptr if the compoent is not in the list
    return nullptr;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_comp[i]->getStarted())
            m_comp[i]->start();

        m_comp[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->draw();
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->onDestroy();

    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}