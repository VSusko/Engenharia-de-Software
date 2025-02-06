#include "unit_tests.h"
#include <cassert>
#include <cmath>


double Expression::execute()
{
    return (source->getValue() * 0.01);
}


void systemTest()
{
    //Default constructor test
    System* p1 = new System();
    assert((p1->getName()) == "");
    assert((p1->getValue()) == 0);

    //Setters test
    p1->setName("test");
    assert((p1->getName()) == "test");
    p1->setValue(10);
    assert((p1->getValue()) == 10);

    //Name and value constructor test
    System* p2 = new System("p2", 20);
    assert((p2->getName()) == "p2");
    assert((p2->getValue()) == 20);

    //Copy operator test
    *p2 = *p1;
    assert((p2->getName()) == "test");
    assert((p2->getValue()) == 10);

    //Copy constructor test
    System* p3 = new System(*p1);
    assert((p3->getName()) == "test");
    assert((p3->getValue()) == 10);

    //Clear test
    p1->clear();
    assert((p1->getValue()) == 0);

    delete p1; delete p2; delete p3;
}


void flowTest()
{
    //Default constructor test
    Expression* flow1 = new Expression();
    assert((flow1->getName()) == "");
    assert((flow1->getSource()) == NULL);
    assert((flow1->getTarget()) == NULL);

    System* p1 = new System("p1", 0);
    System* p2 = new System("p2", 100);
    
    //Constructor with name and 2 systems test
    Expression* flow2 = new Expression("flow2",p1,p2);
    assert((flow2->getName()) == "flow2");
    assert((flow2->getSource()) == p1);
    assert((flow2->getTarget()) == p2);

    //Setters test
    flow1->setName("test");
    assert((flow1->getName()) == "test");
    flow1->setSource(p2);
    assert((flow1->getSource()) == p2);
    flow1->setTarget(p1);
    assert((flow1->getTarget()) == p1);

    //Execute test
    assert((flow1->execute()) == 1);
    
    //Copy constructor test
    Expression* flow3 = new Expression(*flow2);
    assert((flow3->getName()) == "flow2");
    assert((flow3->getSource()) == p1);
    assert((flow3->getTarget()) == p2);

    //Copy operator test
    *flow1 = *flow2;
    assert((flow1->getName()) == "flow2");
    assert((flow1->getSource()) == p1);
    assert((flow1->getTarget()) == p2);

    //Clear test
    flow1->clear();
    assert((flow1->getSource()) == NULL);
    assert((flow1->getTarget()) == NULL);

    delete flow1; delete flow2; delete flow3;
    delete p1; delete p2;
}

void modelTest()
{
    //Default constructor test
    Model* model1 = new Model();
    assert((model1->getName()) == "");

    //Constructor with name and 2 systems test
    Model* model2 = new Model("model2");
    assert((model2->getName()) == "model2");

    //Setters test
    model1->setName("model1");
    assert((model1->getName()) == "model1");


    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 5);
    Expression* flow1 = new Expression("flow1",p1,p2);

    //Add test
    model1->add(p1);
    assert((model1->getSystem("p1")) == p1);
    model1->add(p2);
    assert((model1->getSystem("p2")) == p2);
    model1->add(flow1);
    assert((model1->getFlow("flow1")) == flow1);

    //Copy constructor test
    Model* model3 = new Model(*model1);
    assert((model3->getName()) == "model1");
    assert((model3->getSystem("p1")) == p1);
    assert((model3->getSystem("p2")) == p2);
    assert((model3->getFlow("flow1")) == flow1);

    //Copy operator test
    *model2 = *model3;
    assert((model2->getName()) == "model1");
    assert((model2->getSystem("p1")) == p1);
    assert((model2->getSystem("p2")) == p2);
    assert((model2->getFlow("flow1")) == flow1);

    //Simulate test
    model1->simulate(0,9,1);
    assert(fabs(p1->getValue() - 90.4382) < 0.0001);
    assert(fabs(p2->getValue() - 14.5618) < 0.0001);

    //Remove test
    model1->remove(p1);
    assert((model1->getSystem("p1")) == NULL);

    //Clear test
    model1->clear();
    assert((model1->getSystem("p1")) == NULL);
    assert((model1->getSystem("p2")) == NULL);

    delete model1; delete model2; delete model3;
    delete p1; delete p2; delete flow1;
}