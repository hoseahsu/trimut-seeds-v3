#include <iostream>
#include <cmath>
using namespace std;

double UW,UH,A,B,AB;
double radius(double S){
    return sqrt(S/M_PI);
}

double distance(){
    double rA=radius(A), rB=radius(B);
    double lb=0, ub=rA+rB, d;
    for(int i=0;i<50;i++){
        d = (lb+ub)/2;
        double thetaA = acos((d*d+rA*rA-rB*rB)/(2*rA*d));
        double thetaB = acos((d*d+rB*rB-rA*rA)/(2*rB*d));
        double S = A*thetaA/M_PI + B*thetaB/M_PI - d*rA*sin(thetaA);
        if(S<AB){
            ub = d;
        }else{
            lb = d;
        }
    }
    return d;
}

int main(){
    while(cin>>UW>>UH>>A>>B>>AB,UW){
        double RA=radius(A),RB=radius(B), d=distance();
        double D = hypot(UW-RA-RB,UH-RA-RB);
        if(AB==0) d=RA+RB+0.001;
        if(D<d||UW-RA-RB<0||UH-RA-RB<0||min(UW,UH)<2*max(RA,RB)){
            cout<<"impossible"<<endl;
        }else{
            double XA,YA,XB,YB;
            if(RA>RB){
                XA=YA=RA+0.001;
                XB=XA+(UW-RA-RB)*(d/D);
                YB=YA+(UH-RA-RB)*(d/D);
            }else{
                XB=YB=RB+0.001;
                XA=XB+(UW-RA-RB)*(d/D);
                YA=YB+(UH-RA-RB)*(d/D);
            }
            // cout<<d<<' '<<M_PI*RA*RA<<' '<<M_PI*RB*RB<<endl;
            cout<<fixed;
            cout.precision(9);
            cout<<XA<<' '<<YA<<' '<<RA<<' '<<XB<<' '<<YB<<' '<<RB<<endl;
        }
    }
    return 0;
}