#include <string>
using namespace std;
class Luggage{
public:
	string type;
	float volume;
	virtual float volume() =0;
}

class Box : public Luggage{
	type = "Box";
	float volume(float with,float height,float length) override{
		volume = with*height*length;
	}
}

class Sphere : public Luggage{
	type = "Sphere";
	float volume(float radius) override{
		volume = radius*radius*radius*3.14*4/3;
	}
}

class Cube : public Luggage{
	type = "Cube";
	float volume(float width) override{
		volume = width*width*width;
	}
}

class Pyramid : public Luggage{
	type = "Pyramid";
	float volume(float base, float height) override{
		volume = base*base*height/3;
	}
}


class Cylinder : public Luggage{
	type = "Cylinder";
	float volume(float radius,float height) override{
		volume = radius*radius*height*3.14;
	}
}

