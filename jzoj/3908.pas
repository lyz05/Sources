const 	maxn=100000;maxh=1000000;
type sz=array[1..maxn,1..2] of longint;
var 	i,j,k,n,m,tmp,ans:longint;
        mm:int64;
        a:sz;
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
procedure find(l,r,w:longint);
var mid,ll,rr,wz:longint;
begin
	if (l=r) or (w=0) then begin
		writeln(a[l,2]);
	end;
	if (a[l,1] and (1 shl (w-1)))=(a[r,1] and (1 shl (w-1))) then begin
		find(l,r,w-1);
		exit;
	end;
	if k and (1 shl (w-1))>0 then tmp:=1 else tmp:=0;
	ll:=l;rr:=r;wz:=0;
	while ll<=rr do begin
		mid:=(ll+rr) div 2;
		if a[mid,1] and (1 shl (w-1))>0 then begin
			wz:=mid;
			rr:=mid-1;
		end else ll:=mid+1;
	end;
	if tmp=1 then r:=wz-1 else l:=wz;
	find(l,r,w-1);
end;
begin
        //assign(input,'wu.in');reset(input);
        //assign(output,'wu.out');rewrite(output);
	readln(n,m);
	for i:=1 to n do begin
                read(a[i,1]);
                a[i,2]:=i;
        end;
	qsort(a,1,n);
	for i:=1 to m do begin
		read(k);
		find(1,n,32);
	end;
end.
