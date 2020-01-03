const maxn=100007;p1=99991;p2=67901;
var
        u1,u2,s1,s2:array[-1..100000]of int64;
        t:array[1..2,1..100000,0..1]of longint;
        ha:array[1..2,1..2,-1..100000]of int64;
        h:array[0..maxn,0..2]of int64;
        n,m,i,root1,root2,hh:longint;
        ans:int64;
procedure getha(tt,x:longint);
var
        zt:longint;
begin
        if t[tt,x,0]>0 then
        begin
                getha(tt,t[tt,x,0]);
        end;
        if t[tt,x,1]>0 then
        begin
                getha(tt,t[tt,x,1]);
        end;
        s1[x]:=s1[t[tt,x,0]]+s1[t[tt,x,1]]+1;
        zt:=s1[x];
        ha[tt,1,x]:=
        (ha[tt,1,t[tt,x,0]]*u1[s1[t[tt,x,1]]+1]mod maxn+
        zt*u1[s1[t[tt,x,1]]]mod maxn+
        ha[tt,1,t[tt,x,1]])mod maxn;
        ha[tt,2,x]:=
        (ha[tt,2,t[tt,x,0]]*u2[s1[t[tt,x,1]]+1]mod maxn+
        zt*u2[s1[t[tt,x,1]]]mod maxn+
        ha[tt,2,t[tt,x,1]])mod maxn;
end;
function hash(a,b:longint):longint;
var
        x:longint;
begin
        x:=((a*10007 mod maxn)+b)mod maxn;
        while (h[x,0]>0)and
        ((h[x,1]<>a)or(h[x,2]<>b))do x:=(x+1)mod maxn;
        exit(x);
end;
begin
	assign(input,'3957.in');reset(input);
	//assign(output,'.out');rewrite(output);

        readln(n,m);
        for i:=1 to n do
        begin
                readln(t[1,i,0],t[1,i,1]);
                inc(s1[t[1,i,0]]);
                inc(s1[t[1,i,1]]);
        end;
        for i:=1 to m do
        begin
                readln(t[2,i,0],t[2,i,1]);
                inc(s2[t[2,i,0]]);
                inc(s2[t[2,i,1]]);
        end;
        for i:=1 to n do
        if s1[i]=0 then
        begin
                root1:=i;
                break;
        end;
        for i:=1 to n do
        if s2[i]=0 then
        begin
                root2:=i;
                break;
        end;
        fillchar(s1,sizeof(s1),0);
        fillchar(s2,sizeof(s2),0);
        u1[0]:=1;
        for i:=1 to n do u1[i]:=u1[i-1]*p1 mod maxn;
        u2[0]:=1;
        for i:=1 to m do u2[i]:=u2[i-1]*p2 mod maxn;
        getha(1,root1);
        getha(2,root2);
        for i:=1 to n do
        begin
                hh:=hash(ha[1,1,i],ha[1,2,i]);
                inc(h[hh,0]);
                h[hh,1]:=ha[1,1,i];
                h[hh,2]:=ha[1,2,i];
        end;
        for i:=1 to m do
        begin
                hh:=hash(ha[2,1,i],ha[2,2,i]);
                ans:=ans+h[hh,0];
        end;
        writeln(ans);
end.
