const  u:array[1..4] of integer=(-1,0,1,0);   //�����Ʒ�
      v:array[1..4] of integer=(0,1,0,-1);
      oo=100000000;
type node=record
      x,y,cs,l:longint;
end;
var ft:text;
    n,m,q,ii,i,i1,j1,j,l,w,x,y,x1,y1,x2,y2,x3,y3,es,ey,wei,tou,kx,ky,ans:longint;
    r:array[0..5000000] of node;
    aa,a,fb,fb2:array[0..31,0..31] of longint;
    ff,z,z2:array[0..31,0..31,1..4] of longint;
    f:array[0..31,0..31,1..4,1..4] of longint;
procedure bfs(x,y:longint);  //����
var i,x1,y1:longint;
begin
  wei:=1;
  tou:=0;
  r[wei].x:=x; //r.x������¼�����ƶ��ĺ�����
  r[wei].y:=y; //������
  r[wei].cs:=fb[x,y]; //���������Ƶ�
  while tou<wei do
   begin
    inc(tou);
    for i:=1 to 4 do //�Ƿ���������ĵ��ƶ�
     begin
      x1:=r[tou].x+u[i];
      y1:=r[tou].y+v[i];
      if (a[x1,y1]=1)and(r[tou].cs+1<fb[x1,y1]) then //�����Ƶ����ұ�֮ǰ�Ĳ�����
        begin
         inc(wei);
         r[wei].x:=x1;
         r[wei].y:=y1;
         r[wei].cs:=r[tou].cs+1;
         fb[x1,y1]:=r[wei].cs; //��¼(�ȹ��̽����Ƶ�f��ά������)
        end;
     end;
   end;
end;
begin
	assign(input,'1846.in');reset(input);
  readln(n,m,q);     //���뷽��
  for i:=1 to n do
    begin
    for j:=1 to m do
      read(a[i,j]);
    readln;
    end;
  aa:=a;
  for i:=1 to n do //��ʼ��
   for j:=1 to m do
     begin
      fb2[i,j]:=oo;
      for l:=1 to 4 do
        begin
         z2[i,j,l]:=oo;
         for w:=1 to 4 do f[i,j,l,w]:=oo;
        end;
     end;
  for i:=1 to n do  //Ԥ����
    for j:=1 to m do
     if a[i,j]=1 then  //��������ӿ����ƶ�
       for l:=1 to 4 do  //�ĸ�����
         begin
          x:=i+u[l];
          y:=j+v[l];
          if (x>0)and(x<n+1)and(y>0)and(y<m+1)and(a[x,y]=1) then //���������пո�
            begin
             a[x,y]:=0;  //�ѱ��ƶ�������ֹ�ظ��ƶ�
             fb:=fb2;    //����
             fb[i,j]:=1;  //�ո��Ƶ����λ��
             bfs(i,j);
             for w:=1 to 4 do
               begin
                x1:=x+u[w];
                y1:=y+v[w];
                if (x1>0)and(x1<n+1)and(y1>0)and(y1<m+1)and(fb[x1,y1]<oo) then
                  begin
                  f[i,j,l,w]:=fb[x1,y1];  //��¼��ʾĿ��������λ�ã�x��y���ҿո���Ŀ�����ӵ�k�����ϵ����ڸ���ʱ��Ŀ��������h�����ƶ�1������Ĳ���
                  end;
               end;
             a[x,y]:=1; //����
            end;
         end;
  for ii:=1 to q do
    begin
    read(kx,ky,x,y,es,ey);
    if (x=es)and(y=ey) then //�����ʼλ����Ŀ��λ����ͬ
      begin
       writeln(0);
       continue;
      end;
    fb:=fb2;  //
    a[x,y]:=0; //�ո����Ƶ������
    fb[kx,ky]:=0; //�ո��ƶ�0����
    bfs(kx,ky);  //�ո��ܵ��ĵط�
    wei:=0;
    z:=z2;  //����
    fillchar(ff,sizeof(ff),0);
    for j:=1 to 4 do //Ŀ�������������ƶ�
      begin
       x1:=x+u[j];
       y1:=y+v[j];
       if (x1>0)and(x1<n+1)and(y1>0)and(y1<m+1)and(fb[x1,y1]<oo) then //�ո�����Ƶ�Ŀ���������ڸ���
         begin  //��¼
          inc(wei);
          r[wei].x:=x;
          r[wei].y:=y;
          r[wei].l:=j;  //��ʾ����
          z[x,y,j]:=fb[x1,y1]; //ĳλ����ĳ�����������ƶ�����
          ff[x,y,j]:=1;  //ĳλ����ĳ��������ƶ�
         end;
      end;
    tou:=0;
    while tou<wei do //SPFA
      begin
       inc(tou);
       for i:=1 to 4 do
        begin
         x2:=r[tou].x;
         y2:=r[tou].y;
         x1:=x2+u[r[tou].l]+u[i];
         y1:=y2+v[r[tou].l]+v[i];
         x3:=x2+u[r[tou].l];
         y3:=y2+v[r[tou].l];
        if (f[x2,y2,r[tou].l,i]<>oo)and(z[x3,y3,i]>z[x2,y2,r[tou].l]+f[x2,y2,r[tou].l,i]) then 
begin
            z[x3,y3,i]:=z[x2,y2,r[tou].l]+f[x2,y2,r[tou].l,i];
            if ff[x3,y3,i]=0 then //��¼
              begin
              ff[x3,y3,i]:=1;
              inc(wei);
              r[wei].x:=x3;
              r[wei].y:=y3;
              r[wei].l:=i;
              end;
           end;
         end;
       ff[r[tou].x,r[tou].y,r[tou].l]:=0;
      end;
    ans:=oo;
    for i:=1 to 4 do //����
    if z[es,ey,i]<ans then ans:=z[es,ey,i];
if ans=oo then writeln(-1) 
else writeln(ans);
    a[x,y]:=1; //����
  end;
end.
