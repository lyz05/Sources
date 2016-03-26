var	i,j,k,m,n,cnt:longint;
        wid,hei,ans,tu1,tu2,xf,x1,y1,x2,y2,tmpx,maxx,maxy:qword;
function max(x,y:qword):qword;
begin
	if x>y then exit(x) else exit(y);
end;
function js(x1,y1,x2,y2:qword):qword;
var x,y:qword;
begin
       y:=y2-y1;
       if x2<tmpx then begin
                x:=x2-x1;
                js:=tu1*x*y;
                exit;
       end;
       if x1>=tmpx then begin
                x:=x2-x1;
                js:=tu2*x*y;
                exit;
       end;
       x:=tmpx-x1;
       js:=tu1*x*y;
       x:=x2-tmpx;
       inc(js,tu2*x*y);

end;
begin
	//assign(input,'paper.in');reset(input);
	//assign(output,'paper.out');rewrite(output);
	readln(k);
	for i:=1 to k do begin
		readln(wid,hei,xf,cnt,x1,y1,x2,y2);
		maxx:=max(xf,wid-xf);
		maxy:=hei div (cnt+1);
		if maxx=xf then tmpx:=wid-xf else tmpx:=xf;
		tu1:=2*(cnt+1);
		tu2:=1*(cnt+1);
		ans:=wid*hei;
		ans:=ans-js(x1,y1,x2,y2);
		writeln(ans);
	end;
	//close(input);close(output);
end.
input
3
5 6 2 2 1 1 3 2
5 6 3 5 1 1 3 1
5 6 3 5 1 1 2 1
output
21
12
6

