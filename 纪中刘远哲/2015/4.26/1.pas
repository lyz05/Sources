uses	math;
const	maxn=1000000;
var	i,j,k,m,n,x,y:longint;
	h:array[1..4*maxn,1..2] of longint;
procedure change(x,l,r,st,en:longint);
var	mid:longint;
begin
	if (l=st) and (r=en) then begin
		inc(h[x,1]);inc(h[x,2]);
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
		mid:=(l+r)>>1;
		if en<=mid then change(x+x,l,mid,st,en)
		else if st>mid then change(x+x+1,mid+1,r,st,en)
		else begin
			change(x+x,l,mid,st,mid);
			change(x+x+1,mid+1,r,mid+1,en);
		end;
		h[x,1]:=max(h[x+x,1],h[x+x+1,1]);
	end;
end;
function quary(x,l,r,st,en:longint):longint;
var	mid:longint;
begin
	if (l=st) and (r=en) then exit(h[x,1]);
	inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
	inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
	h[x,2]:=0;
	mid:=(l+r)>>1;
	if en<=mid then exit(quary(x+x,l,mid,st,en))
	else if st>mid then exit(quary(x+x+1,mid+1,r,st,en))
	else
	exit(max(quary(x+x,l,mid,st,mid),quary(x+x+1,mid+1,r,mid+1,en)));
end;
begin
	assign(input,'reserve.in');reset(input);
	assign(output,'reserve.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(x,y);
		change(1,1,maxn,x,y);
	end;
	writeln(quary(1,1,maxn,1,maxn));
	
	close(input);close(output);

end.
