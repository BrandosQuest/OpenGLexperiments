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
    //FragColor = vec4(1.0f, 1.0f, 1.0f , 1.0f){;
    //float distanceFromCircleNormalized=abs(lenght(pos)-0.5)*(1/sqrt(2));
    float acceleratedTime=timeFormInit*1;
    //float acceleratedTime=10*sin(timeFormInit);
    float numOfCircles=4;
    float distanceFromCircleNormalized=sin(lenght(pos)*numOfCircles*2+acceleratedTime)/8;
    //distanceFromCircleNormalized= smoothstep(0.0, 0.1, distanceFromCircleNormalized);
    distanceFromCircleNormalized= abs(distanceFromCircleNormalized);
    float glow=0.02;
    distanceFromCircleNormalized= glow/distanceFromCircleNormalized;
    FragColor = vec4(distanceFromCircleNormalized, distanceFromCircleNormalized, distanceFromCircleNormalized , 1.0f);


}
/*
x^2 + y^2 = r^2

y=sqrt(x^2-r^2);


if(pos.y==sqrt((pos.x*pos.x)-(0.5*0.5))){
        FragColor = vec4(1.0, 1.0, 1.0 , 1.0f);
    }
    
    if((0.5-lenght(pos))<0.1 && (0.5-lenght(pos))>0.0){
        FragColor = vec4(1.0, 1.0, 1.0 , 1.0f);
    }
*/