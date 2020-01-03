var
    l,r,ri,q,x,y,i,n,m,mid,j:longint;
    a:array[1..20000,1..3] of longint;
    bz:array[1..100,1..100] of boolean;
    f:array[1..1000] of longint;
function max(l,r:longint):longint;
begin
    if l<r then exit(r);exit(l);
end;
function get(x:longint):longint;
begin
    if f[x]=0 then exit(x);f[x]:=get(f[x]);exit(f[x]);
end;
function pd(x,y,z:longint):boolean;
var i,fx,fy:longint;
begin
    fillchar(f,sizeof(f),0);
    for i:=1 to m do
    if a[i,3]>=z then begin
       fx:=get(a[i,1]);fy:=get(a[i,2]);
       if fx<>fy then f[fx]:=fy;
    end;
    exit(get(x)=get(y));
end;
begin
	//assign(input,'1141.in');reset(input);
    readln(n,m);
    for i:=1 to m do begin readln(a[i,1],a[i,2],a[i,3]);bz[a[i,1],a[i,2]]:=true;bz[a[i,2],a[i,1]]:=true;ri:=max(ri,a[i,3]);end;
    readln(q);
    for i:=1 to n do
       for j:=i+1 to n do
       if not bz[i,j] then begin inc(m);a[m,1]:=i;a[m,2]:=j;a[m,3]:=maxlongint;end;
    for q:=1 to q do begin
        readln(x,y);
        l:=0;r:=ri;
        while l<r do begin
           mid:=(l+r)shr 1;
           if pd(x,y,mid) then l:=mid else r:=mid-1;
           if l=r-1 then break;
        end;
        if pd(x,y,r) then l:=r;
        if pd(x,y,maxlongint-1) then writeln(-1) else writeln(l);
    end;
end.
