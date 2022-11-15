void F(HDC hdc,int x,int y,int a)
{   //Sleep(200);
    if(a>2)
    {   F(hdc,x-a,y-a,a/2);
        F(hdc,x-a,y+a,a/2);
        F(hdc,x+a,y-a,a/2);
        F(hdc,x+a,y+a,a/2);
    }
    Rectangle(hdc,x-a,y-a,x+a,y+a);
}