const	maxc=1000005;maxn=200005;
type	node=record
		l,r,mid,p:longint;
	end;
var	i,j,k,m,n,ch,num,sum:longint;
	car:array[1..maxc] of longint;
	h:array[1..4*maxn] of node;
procedure merger(x:longint);
var	t:longint;
begin
	if h[x+x].l>0 then h[x].l:=h[x+x].l else h[x].l:=h[x+x+1].l;
	if h[x+x+1].r>0 then h[x].r:=h[x+x+1].r else h[x].r:=h[x+x].r;
	h[x].mid:=h[x+x].mid;
	h[x].p:=h[x+x].p;
	if (h[x+x+1].l>0) and (h[x+x].r>0) then begin
		t:=(h[x+x+1].l-h[x+x].r) div 2;
		if t>h[x].mid then begin
			h[x].mid:=t;
			h[x].p:=(h[x+x+1].l+h[x+x].r) div 2;
		end;
		if h[x+x+1].mid>h[x].mid then begin
			h[x].mid:=h[x+x+1].mid;
			h[x].p:=h[x+x+1].p;
		end;
	end;
end;
procedure work(x,l,r,num,kind:longint);
var	mid:longint;
begin
	if l=r then begin
		if kind=2 then begin
			h[x].l:=0;h[x].r:=0;
			h[x].mid:=0;h[x].p:=0;
		end else begin
			h[x].l:=l;h[x].r:=r;
			h[x].mid:=0;h[x].p:=0;
		end;
		exit;
	end;
	mid:=(l+r)>>1;
	if num<=mid then work(x+x,l,mid,num,kind) else work(x+x+1,mid+1,r,num,kind);
	merger(x);
end;
begin
	assign(input,'3480.in');reset(input);
	readln(n,m);
	for i:=1 to m do begin
		readln(ch,num);
		if ch=1 then begin
			if h[1].l=0 then begin
				car[num]:=1;
			end else begin
				sum:=-maxlongint;
				if h[1].l-1>sum then begin
					sum:=h[1].l-1;
					car[num]:=1;
				end;
				if h[1].mid>sum then begin
					sum:=h[1].mid;
					car[num]:=h[1].p;
				end;
				if n-h[1].r>sum then begin
					sum:=n-h[1].r;
					car[num]:=n;
				end;
			end;
			writeln(car[num]);
			work(1,1,n,car[num],1);
		end else begin
			work(1,1,n,car[num],2);
		end;
	end;
end.
