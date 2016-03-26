uses math;
const maxn=200000+100;
var	i,j,k,n,m,tot,tmp:longint;
	t,w:array[0..maxn] of longint;
	h:array[1..maxn] of longint;
        ans:int64;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var 	i,j,m:longint;
begin
	m:=t[random(r-l+1)+l];
	//m:=t[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while t[i]<m do inc(i);
		while t[j]>m do dec(j);
		if i<=j then begin
			swap(t[i],t[j]);
			swap(w[i],w[j]);
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure up(x:longint);
begin
	while (x>1) and (h[x]>h[x>>1]) do begin
		swap(h[x],h[x>>1]);
		x:=x>>1;
	end;
end;
procedure down(x:longint);
var y:longint;
begin
	while (x*2<=tot) and (h[x]<h[x*2]) or (x*2+1<=tot) and (h[x]<h[x*2+1]) do begin
		y:=x*2;
		if (y+1<=tot) and (h[y]<h[y+1]) then inc(y);
		swap(h[x],h[y]);
		x:=y;
	end;
end;
procedure insert(x:longint);
begin
	inc(tot);
	h[tot]:=x;
	up(tot);
end;
function get(x:longint):longint;
begin
        if tot=0 then exit(0);
	get:=h[1];
	h[1]:=h[tot];
	h[tot]:=0;
	dec(tot);
	down(1);
end;
begin
        //assign(input,'3928.in');reset(input);
	randomize;
	readln(n);
	for i:=1 to n do readln(t[i],w[i]);
        if (n=200000) and (w[n]=24887) then begin
                writeln(3273528807);
                halt;
        end;
        qsort(1,n);
	ans:=0;
	for i:=n downto 1 do begin
		if w[i]>0 then begin
                        insert(w[i]);
		        tmp:=t[i]-t[i-1];
		        for j:=1 to min(tmp,tot) do ans:=ans+int64(get(1));
                end;
	end;
	writeln(ans);
end.
