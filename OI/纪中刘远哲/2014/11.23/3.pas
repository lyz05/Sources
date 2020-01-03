const	maxn=20000;maxm=100000;
type	node=record
		y,val,next,i:longint;
	end;
	arr=array[0..maxm] of longint;
	sz=arr;
var	i,j,k,m,n,tot,tmp,ans,x,y,z:longint;
	p:array[1..maxn] of boolean;
	e:array[1..maxn] of longint;
	h:array[1..2*maxm] of node;
	dl:array[0..2] of arr;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]<m do inc(i);
  while a1[j]>m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure add(x,y,z,k:longint);
begin
	inc(tot);
	h[tot].val:=z;
	h[tot].y:=y;
	h[tot].i:=k;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure pd;
var	i,j,len:longint;
begin
	qsort(dl[0],1,dl[0][0]);
	qsort(dl[1],1,dl[1][0]);
	i:=1;j:=1;
	while (i<=dl[0][0]) and (j<=dl[1][0]) do begin
		while dl[0][i]>dl[1][j] do inc(j);
		while dl[0][i]<dl[1][j] do inc(i);
		if dl[0][i]=dl[1][j] then begin
			inc(dl[2][0]);
			dl[2][dl[2][0]]:=dl[0][i];
			inc(i);inc(j);
		end;
	end;
	//min(dl[0][0],dl[1][0]);
	dl[0]:=dl[2];
end;
procedure d(deep,x,z:longint);
var	i,val,y:longint;
begin
	if tmp>ans then exit;
	if deep>n then exit;
	if x=z then begin
		if tmp=ans then pd;
		if tmp<ans then begin
			ans:=tmp;
			dl[0]:=dl[1];
			//len:=deep-1;
		end;
		exit;
	end;
	i:=e[x];
	while i<>0 do begin
		y:=h[i].y;
		val:=h[i].val;
		if p[y] then begin
                        i:=h[i].next;
                        continue;
                end;

		inc(dl[1,0]);
		dl[1,dl[1,0]]:=h[i].i;
		p[y]:=true;
		inc(tmp,val);
			d(deep+1,y,z);
		dec(tmp,val);
		p[y]:=false;
		dl[1,dl[1,0]]:=0;
		dec(dl[1,0]);

		i:=h[i].next;
	end;
end;
begin
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y,z);
		add(x,y,z,i);
		add(y,x,z,i);
	end;
        ans:=maxlongint-500;
	p[1]:=true;
	d(1,1,n);

        qsort(dl[0],1,dl[0,0]);
	writeln(dl[0,0]);
	for i:=1 to dl[0,0] do write(dl[0,i],' ');
	writeln;
end.
