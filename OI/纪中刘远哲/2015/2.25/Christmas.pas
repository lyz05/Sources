uses	math;
const	maxn=100000;
var	i,m,n,x,y,z:longint;
	ch:char;
	h:array[1..4*maxn,1..4] of longint;
procedure build(x,l,r:longint);
var	mid:longint;
begin
	if l=r then begin
                read(h[x,1]);
        end else begin
		mid:=(l+r)>>1;
		build(x+x,l,mid);
		build(x+x+1,mid+1,r);
                h[x,1]:=min(h[x+x,1],h[x+x+1,1]);
	end;
end;
procedure add(x,l,r,st,en,val:longint);
var	mid:longint;
begin
	if (l=st) and (r=en) then begin
		inc(h[x,1],val);inc(h[x,2],val);inc(h[x,3],1);
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
                if h[x,1]>h[x+x,1] then begin
                        h[x+x,1]:=h[x,1];
                        inc(h[x+x,4],h[x,4]);
                end;
                if h[x,1]>h[x+x+1,1] then begin
                        h[x+x+1,1]:=h[x,1];
			inc(h[x+x+1,4],h[x,4]);
                end;
		h[x,4]:=0;
		inc(h[x+x,3],h[x,3]);inc(h[x+x+1,3],h[x,3]);
		h[x,3]:=0;

		mid:=(l+r)>>1;
		if en<=mid then add(x+x,l,mid,st,en,val)
		else if st>mid then add(x+x+1,mid+1,r,st,en,val)
		else begin
			add(x+x,l,mid,st,mid,val);
			add(x+x+1,mid+1,r,mid+1,en,val);
		end;
		h[x,1]:=min(h[x+x,1],h[x+x+1,1]);
	end;
end;
procedure maxx(x,l,r,st,en,val:longint);
var	mid,t:longint;
begin
	if (l=st) and (r=en) then begin
		t:=max(h[x,1],val);
		if h[x,1]<>t then begin
			h[x,1]:=t;inc(h[x,4]);
		end;
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
                if h[x,1]>h[x+x,1] then begin
                        h[x+x,1]:=h[x,1];
                        inc(h[x+x,4],h[x,4]);
                end;
                if h[x,1]>h[x+x+1,1] then begin
                        h[x+x+1,1]:=h[x,1];
			inc(h[x+x+1,4],h[x,4]);
                end;
		h[x,4]:=0;
		inc(h[x+x,3],h[x,3]);inc(h[x+x+1,3],h[x,3]);
		h[x,3]:=0;

		mid:=(l+r)>>1;
		if en<=mid then maxx(x+x,l,mid,st,en,val)
		else if st>mid then maxx(x+x+1,mid+1,r,st,en,val)
		else begin
			maxx(x+x,l,mid,st,mid,val);
			maxx(x+x+1,mid+1,r,mid+1,en,val);
		end;
		h[x,1]:=min(h[x+x,1],h[x+x+1,1]);
	end;
end;
procedure quary(x,l,r,z:longint);
var	mid:longint;
begin
	if l=r then begin
		inc(h[x,3],h[x,4]);
		h[x,4]:=0;
		writeln(h[x,1],' ',h[x,3]);
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
                if h[x,1]>h[x+x,1] then begin
                        h[x+x,1]:=h[x,1];
                        inc(h[x+x,4],h[x,4]);
                end;
                if h[x,1]>h[x+x+1,1] then begin
                        h[x+x+1,1]:=h[x,1];
			inc(h[x+x+1,4],h[x,4]);
                end;
		h[x,4]:=0;
		inc(h[x+x,3],h[x,3]);inc(h[x+x+1,3],h[x,3]);
		h[x,3]:=0;

		mid:=(l+r)>>1;
		if (l<=z) and (z<=mid) then begin
			quary(x+x,l,mid,z);
		end else begin
			quary(x+x+1,mid+1,r,z);
		end;
	end;
end;
begin
	//assign(input,'data.in');reset(input);
	//assign(output,'output.txt');rewrite(output);

	readln(n);
	build(1,1,n);
	readln(m);
	for i:=1 to m do begin
		read(ch);
		if ch='Q' then readln(x) else readln(x,y,z);
		case ch of
			'A':if z<>0 then add(1,1,n,x,y,z);
			'M':maxx(1,1,n,x,y,z);
			'Q':quary(1,1,n,x);
		end;
	end;
end.
