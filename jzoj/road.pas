type
        lzx=record
                y,next:longint;
        end;

var
        tot,i,j,n,m,x,y,z,s,t:longint;
        e:array[1..200000] of lzx;
        g,a,d:array[1..10000] of longint;
        p,b:array[1..10000] of boolean;

procedure add(x,y:longint);
begin
        inc(tot);
        e[tot].y:=y;
        e[tot].next:=g[x];
        g[x]:=tot;
end;

procedure bfs(x,s:longint);
var     l,r,i,j:longint;
begin
        l:=0;
        r:=1;
        a[1]:=x;
        fillchar(p,sizeof(p),false);
        p[x]:=true;
        fillchar(d,sizeof(d),$7f);
        d[x]:=0;
        while l<r do begin
                inc(l);
                x:=a[l];
                i:=g[x];
                while i<>0 do begin
                        j:=e[i].y;
                        if (not p[j]) and (b[j]) then begin
                                p[j]:=true;
                                inc(r);
                                d[j]:=d[x]+1;
                                if j=s then exit;
                                a[r]:=j;
                        end;
                        i:=e[i].next;
                end;
        end;
end;

procedure del;
var     i,j,x:longint;
begin
        for x:=1 to n do
		if not p[x] then begin
              	  	i:=g[x];
            	  	while i<>0 do begin
             	           j:=e[i].y;
          	           b[j]:=false;
                	   i:=e[i].next;
                	end;
        	end;
end;

begin
        assign(input,'road.in');reset(input);
        //assign(output,'road.out');rewrite(output);
        readln(n,m);
        for i:=1 to m do begin
                readln(x,y);
                add(y,x);
        end;
        readln(s,t);
        fillchar(b,sizeof(b),true);
        bfs(t,0);
        del;
        bfs(t,s);
        if not p[s] then writeln(-1) else writeln(d[s]);
        //close(input);close(output);
end.
