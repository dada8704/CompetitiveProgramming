#include<iostream>
#include<string>


class Engine
{
private:
    int CC;
    std::string type;
    int weight;
public:
	//construction
    Engine(){CC = 0, type = "", weight = 0;}
    Engine(int CC, std::string type, int weight){this->CC = CC, this->type = type, this->weight = weight; 
    	std::cout << "Construction!!" << std::endl;}
    //destruction
    ~Engine () {std::cout << "Destruction!!" << std::endl;}
    //copy construction
    Engine(const Engine& x) : CC(x.CC), type(x.type), weight(x.weight){std::cout << "copy constrution!!" << std::endl;}

    //copy assignment
    Engine& operator= (const Engine& x)
    {
    	std::cout << "copy constrution!!" << std::endl;
    	this->CC = x.CC, this->type = x.type, this->weight = x.weight;
    	return *this;
    }

    //move construction is not complete
    Engine(Engine&& x) : CC(x.CC), type(x.type), weight(x.weight) 
    {
    	std::cout << "move constrution!!" << std::endl;
    	x.CC = -1, x.type = "", x.weight = -1;
    }
    //move assignment
    Engine& operator= (Engine&& x)
    {
    	std::cout << "move assignment" << std::endl;
    	this->CC = x.CC, this->type = x.type, this->weight = x.weight;
    	x.CC = -1, x.type = "", x.weight = -1;
    	return *this;
    }


    void Print() {std::cout << "CC: " << CC << " type: " << type << " weight: " << weight << std::endl;}

};


int main(void)
{
    Engine A(1, "jhhlab", 8);
    A.Print();
    Engine B;  
    B = std::move(Engine(3, "haha", 9));
    B.Print();
}


