uses	math;
const	haha=maxlongint;

var
        a,h:array[0..100000] of longint;
        n,i,z,y,x,ans:longint;

procedure build(l,r,nod:longint);
begin
        if (l=r) then begin 
		h[nod]:=a[l];
		exit;
	end;
        build(l,(l+r) div 2,nod+nod);
        build((l+r) div 2+1,r,nod+nod+1);
        h[nod]:=min(h[nod+nod],h[nod+nod+1]);
end;

function del(p,q:longint):longint;
begin
        if (h[p+p]<>q)and(h[p+p+1]<>q) then begin 
		h[p]:=haha;
		exit(p);
	end;
        if h[p+p]=q then del:=del(p+p,q)
                else del:=del(p+p+1,q);
        h[p]:=min(h[p+p],h[p+p+1]);
end;

procedure insert(p:longint);
begin
        if p=0 then exit;
        h[p]:=min(h[p+p],h[p+p+1]);
        insert(p div 2);
end;

begin
        //assign(input,'fruit.in');reset(input);
        //assign(output,'fruit.out');rewrite(output);
        readln(n);
        for i:=1 to 10000 do h[i]:=haha;
	h[0]:=-haha;
        for i:=1 to n do read(a[i]);
        build(1,n,1);
	ans:=0;
        for i:=1 to n-1 do
        begin
                x:=h[1];del(1,x);
                y:=h[1];z:=del(1,y);
                h[z]:=x+y;
		inc(ans,h[z]);
                insert(z div 2);
        end;
        writeln(ans);
        //close(input);
        //close(output);
end.
