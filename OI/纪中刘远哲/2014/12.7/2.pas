var	i,n,p:longint;
	x,y,g,f,l:int64;
        ans:qword;
	a:array[0..20] of integer;
procedure push(x:int64);
var	i:longint;
begin
	for i:=1 to n do begin
		a[n-i+1]:=x mod 10;
		x:=x div 10;
	end;
end;
procedure get(var x:int64;m:integer);
var	i:longint;
begin
	x:=0;
	for i:=1 to n do begin
		if m=1 then x:=x+a[i] else x:=x+a[n-i+1];
                x:=x*10;
	end;
        x:=x div 10;
end;
procedure qsort(l,r:longint);
var m,i,j:longint;
begin
 m:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]>m do inc(i);
  while a[j]<m do dec(j);
  if i<=j then begin
   a[0]:=a[i];
   a[i]:=a[j];
   a[j]:=a[0];
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
begin
	//assign(input,'2.in');reset(input);
	//assign(output,'2.out');rewrite(output);

	//readln(n,p);
        //p:=maxlongint;

        ans:=0;x:=1;y:=1;
	for i:=1 to n do y:=y*10;
        x:=y div 10;
	dec(y);
        n:=10;
        x:=9975084201;
	//while x<=y do begin
		push(x);
		qsort(1,n);
		get(g,1);
		get(l,2);
		f:=g-l;
		if f=x then begin
			ans:=(ans+sqr(x));
		end;
                inc(x);
	//end;
	writeln(ans);

        //end;
end.
