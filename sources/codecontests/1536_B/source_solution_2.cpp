#include <cstdio>
char s[1005];
int main()
{
    int t,n;
    bool f,ff;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        f=false;
        for(char a='a';a<='z'&&!f;a++)
        {
            ff=false;
            for(int i=0;i<n;i++)
                if(s[i]==a)
                    ff=true;
            if(!ff)
            {
                printf("%c\n",a);
                f=true;
            }
        }
        for(char a='a';a<='z'&&!f;a++)
            for(char b='a';b<='z'&&!f;b++)
            {
                ff=false;
                for(int i=0;i<n-1;i++)
                    if(s[i]==a&&s[i+1]==b)
                        ff=true;
                if(!ff)
                {
                    printf("%c%c\n",a,b);
                    f=true;
                }
            }
        for(char a='a';a<='z'&&!f;a++)
            for(char b='a';b<='z'&&!f;b++)
                for(char c='a';c<='z'&&!f;c++)
                {
                    ff=false;
                    for(int i=0;i<n-2;i++)
                        if(s[i]==a&&s[i+1]==b&&s[i+2]==c)
                            ff=true;
                    if(!ff)
                    {
                        printf("%c%c%c\n",a,b,c);
                        f=true;
                    }
                }
    }
    return 0;
}
