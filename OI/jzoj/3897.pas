const maxn=100000;maxm=150000;maxt=100000;
type sz=array[0..maxm,1..2] of longint;
var	i,j,m,n,t,mm:longint;
	map:sz;
	q:array[1..maxt,1..3] of longint;
	a,b:array[0..maxn] of longint;
     //p:array[0..maxm+1] of boolean;
procedure swap(x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m1,i,j,m2:longint;
begin
 m1:=a1[(l+r) div 2,1];
 m2:=a1[(l+r) div 2,2];
 i:=l;
 j:=r;
 repeat
  while (a1[i,1]<m1) or ((a1[i,1]=m1) and (a1[i,2]<m2)) do inc(i);
  while (a1[j,1]>m1) or ((a1[j,1]=m1) and (a1[j,2]>m2)) do dec(j);
  if i<=j then begin
   a1[0]:=a1[i];
   a1[i]:=a1[j];
   a1[j]:=a1[0];
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
function getfather(x:longint):longint;
begin
	if a[x]=x then exit(x);
	a[x]:=getfather(a[x]);
	exit(a[x]);
end;
procedure lj(x,y:longint);
var xf,yf:longint;
begin
	xf:=getfather(x);
	yf:=getfather(y);
	a[xf]:=yf;
end;
function pd(x,y:longint):boolean;
var i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	if i=j then exit(true) else exit(false);
end;
procedure cut(x,y,l,r:longint);
var i,mid:longint;
begin
	while l<r do begin
		mid:=(l+r) div 2;
		while (map[mid,1]=0) and (mid<=r) do inc(mid);
		if mid=r+1 then begin
			dec(mid);
			while (map[mid,1]=0) and (mid>=l) do dec(mid);
		end;
		if (mid<l) or (mid>r) then writeln('err');
		if (map[mid,1]=x) and (map[mid,2]=y) then break;
		if (map[mid,1]>x) or ((map[mid,1]=x) and (map[mid,2]>y)) then
			r:=mid-1 else l:=mid+1;
	end;
        if l>=r then mid:=(l+r) div 2;
        if map[mid,1]=0 then begin
                writeln('err1');
        end;
	map[mid,1]:=0;
end;
begin
        assign(input,'3897.in');reset(input);
	readln(n,mm,t);
	m:=mm;
	for i:=1 to m do begin
		readln(map[i,1],map[i,2]);
                if map[i,1]>map[i,2] then begin
				swap(map[i,1],map[i,2]);
                end;
	end;
	qsort(map,1,m);

	for i:=1 to t do begin
		readln(q[i,1],q[i,2],q[i,3]);
		q[i,2]:=q[i,2] xor m;
		q[i,3]:=q[i,3] xor m;
		if q[i,2]>q[i,3] then swap(q[i,2],q[i,3]);
		if q[i,1]=1 then begin
			cut(q[i,2],q[i,3],1,mm);
			dec(m);
		end;
	end;
	for i:=1 to n do a[i]:=i;
	for i:=1 to mm do
		if map[i,1]<>0 then lj(map[i,1],map[i,2]);
	for i:=t downto 1 do begin
		if q[i,1]=1 then lj(q[i,2],q[i,3]) else begin
			inc(b[0]);
			if pd(q[i,2],q[i,3]) then b[b[0]]:=1 else b[b[0]]:=0;
		end;
	end;
	for i:=b[0] downto 1 do writeln(b[i]);

end.
