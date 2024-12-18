const 	maxn=100000;maxh=1000000;
type sz=array[1..maxn,1..2] of longint;
var 	i,j,k,n,m,tmp,ans:longint;
        mm:int64;
        a:sz;
        b:array[1..maxn] of longint;
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
 m:=a1[(l+r) div 2,1];
 i:=l;
 j:=r;
 repeat
  while a1[i,1]<m do inc(i);
  while a1[j,1]>m do dec(j);
  if i<=j then begin
   swap(a1[i,1],a1[j,1]);
   swap(a1[i,2],a1[j,2]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
function solve(l,r,m,k:longint):longint;
var i,mid:longint;
begin
	while l<r do begin
	        mid:=(l+r) div 2;
		if a[mid,1]=m then break;
		if a[mid,1]<m then l:=mid+1 else r:=mid-1;
	end;
	exit(a[mid,2]);
        //if l=r then inc(r);
	//if a[l,1] xor k>a[r,1] xor k then exit(a[l,2]) else exit(a[r,2]);
end;
begin
        assign(input,'wu.in');reset(input);
        assign(output,'wu.out');rewrite(output);
	readln(n,m);
	for i:=1 to n do begin
                read(a[i,1]);
                a[i,2]:=i;
        end;
	for i:=1 to m do read(b[i]);
	qsort(a,1,n);
	for i:=1 to m do begin
		k:=b[i];
		j:=0;
		while k<>0 do begin
			k:=k div 2;
			inc(j);
		end;
		mm:=1;
		for k:=1 to j do mm:=mm*2;
		mm:=mm-1;
		mm:=mm xor b[i];
		writeln(solve(1,n,mm,b[i]));
	end;
end.
