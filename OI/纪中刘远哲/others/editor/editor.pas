type	node=record
		l,r,val:longint
	end;
var 	n,i,j,k,t,gb,tot,first:longint;
	s1,s2:string;
	ch:char;
	a:array[1..100000] of node;
procedure input1(k:longint);
var 	i,j:longint;
begin
	inc(tot);
	if tot=1 then begin
		a[1].val:=k;
                a[1].l:=0;
                a[1].r:=2;
                a[2].l:=1;
                gb:=2;
                exit;
	end;
	a[a[gb].l].r:=tot;
	a[tot].l:=a[gb].l;
        inc(gb);
	a[gb].l:=tot;
	a[tot].r:=gb;
	a[tot].val:=k;
end;
procedure solve(k:longint);
var 	i,tmp,max:longint;
begin
	i:=first;
        MAX:=-maxlongint+100;
	tmp:=0;
	while k<>0 do begin
		tmp:=tmp+a[i].val;
		if tmp>max then max:=tmp;
		i:=a[i].r;
		dec(k);
	end;
	writeln(max);
end;
procedure delete;
var 	i,lgb:longint;
begin
	lgb:=a[gb].l;
	if a[lgb].l=0 then first:=a[lgb].r;
        if first=0 then first:=1;
	a[lgb].val:=0;
	a[a[lgb].l].r:=gb;
	a[gb].l:=a[lgb].l;
	a[lgb].l:=0;
	a[lgb].r:=0;
end;
begin
        //assign(input,'editor.in');reset(input);
        //assign(output,'editor.out');rewrite(output);

        readln(n);
	gb:=1;first:=1;
	for i:=1 to n do begin
		readln(s1);
		ch:=s1[1];
		t:=pos(' ',s1);
		if t<>0 then s2:=copy(s1,t+1,length(s1)-t);
		val(s2,k);
		case ch of
			'I':input1(k);
			'D':delete;
			'L':gb:=a[gb].l;
			'R':gb:=a[gb].r;
			'Q':solve(k);
		end;
	end;

        //close(input);close(output);

end.

