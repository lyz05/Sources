type sz=array[0..100000,0..4] of longint;
     sz1=array[0..4] of longint;
var	i,j,k,m,n,lena,lenb,ans,tmp:longint;
	a,b:sz;//a ºáÏß bÊúÏß
procedure swap(var x,y:sz1);
var t:sz1;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure swap1(var x,y:longint);
begin
        x:=x xor y;
        y:=x xor y;
        x:=x xor y;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2,0];
 i:=l;
 j:=r;
 repeat
  while a1[i,0]>m do inc(i);
  while a1[j,0]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
function min(x,y:longint):longint;
begin
	if x<y then exit(x) else exit(y);
end;
function solve(x,y:sz1):longint;
var tmp1,tmp2:longint;
begin
      if x[1]>x[3] then swap1(x[1],x[3]);
      if y[4]>y[2] then swap1(y[4],y[2]);
      if (y[1]<=x[3]) and (y[1]>=x[1]) and (x[2]<=y[2]) and (x[2]>=y[4]) then
      begin
		tmp1:=min(abs(y[2]-x[4]),abs(y[4]-x[4]));
		tmp2:=min(abs(y[1]-x[1]),abs(y[1]-x[3]));
		solve:=min(tmp1,tmp2);
      end else solve:=-1;
end;
procedure print;
begin
	if ans=0 then writeln('Human intelligence is really terrible')
		else writeln(ans);
        halt;
end;
begin
	readln(n);
	for i:=1 to n do begin
		for j:=1 to 4 do read(a[0,j]);
		if a[0,2]=a[0,4] then begin
                        inc(lena);
			a[0,0]:=abs(a[0,1]-a[0,3]);
			a[lena]:=a[0];
		end;
		if a[0,1]=a[0,3] then begin
                        inc(lenb);
			a[0,0]:=abs(a[0,2]-a[0,4]);
			b[lenb]:=a[0];
		end;
	end;
	qsort(a,1,lena);
	qsort(b,1,lenb);
	for i:=1 to lena do begin
		for j:=1 to lenb do begin
			tmp:=solve(a[i],b[j]);
			if (tmp>=0) and (tmp>ans) then ans:=tmp;
			if (ans>(a[i,0] div 2)) and (ans>(b[j,0] div 2)) then print;
		end;
	end;
	print;
end.
