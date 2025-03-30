#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 ourCoords;

uniform float timeFormInit;
uniform float width;
uniform float hight;

float lenght(vec2 pos){
    return sqrt((pos.x*pos.x)+(pos.y*pos.y));
}

void main()
{
    vec2 pos= vec2(ourCoords.x, ourCoords.y);//coord system with 2 axis 
    pos.x = pos.x * width/hight;// normalising x coord indiendently of the screen ratio

    float l = lenght(pos);//for every pixel I calculate the distance from the center
    //float greyValue= ((sin(timeFormInit)*l)+1)/2;
    float greyValue= (sin(timeFormInit)+1)/2;
    FragColor = vec4(greyValue, greyValue, greyValue , 1.0f);
    //FragColor = vec4(1.0f, 1.0f, 1.0f , 1.0f);
}
