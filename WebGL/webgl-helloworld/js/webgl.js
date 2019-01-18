/**
 * game engine startup.
 */
!(function () {
    // first init global variable
    let _global = typeof window === "undefined" ? global : window;

    function logger() {
        const proto = logger.prototype;

        proto.log = () => {
            console.log(...arguments);
        }

        proto.error = (err) => {
            console.error(...arguments);
        }

        proto.warn = () => {
            console.warn(...arguments);
        }

        proto.trace = () => {
            console.trace(...arguments);
        }

        proto.alert = () => {
            alert(...arguments);
        }
    }

    function loadShader(type, source) {
        const shader = gl.createShader(type);
        gl.shaderSource(shader, source);
        gl.compileShader(shader);
        if(!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
            alert('compile shader fail =>', gl.getShaderInfoLog(shader));
            gl.deleteShader(shader);
            return null;
        }
        return shader;
    }

    function linkProgram(vShaderSource, fShaderSource) {
        let program = gl.createProgram();
        let vShader = loadShader(gl, gl.VERTEX_SHADER, vShaderSource);
        let vShader = loadShader(gl, gl.FRAGMENT_SHADER, fShaderSource);

        gl.attachShader(program,vShader);
        gl.attachShader(program,fShader);
        gl.linkProgram(program);

        if(!gl.getProgramParameter(program, gl.LINK_STATUS)) {
            alert('link program fail =>', gl.getProgramInfoLog(program));
            gl.deleteProgram(program);
            return null;
        }
        gl.deleteShader(vShader);
        gl.deleteShader(fShader);
        return program;
    }

    function createVertexBuffer(data) {
        const bufferId = gl.createBuffer(1);
        gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.STATIC_DRAW);
        // cancle bind buffer data
        gl.bindBuffer(gl.ARRAY_BUFFER, 0);
        return bufferId;
    }

    function getAttrLocation(shaderProgram, feildName) {
        let location = gl.getAttribLocation(shaderProgram, feildName);
        if(location < 0) {
            logger.err(`获取着色器这个字段${feildName}失败`);
        }
        return location;
    }

    function setShaderDataFormat(locationId, vertexLen, vertexType, normalized, stride, offset) {
        gl.vertexAttribPointer(locationId, vertexLen, vertexType, normalized, stride, offset);
        gl.enableVertexAttribArray(locationId);
    }

    function drawScene(program, bufferId, firstIndex, vertexNum) {
        gl.clearColor(.0,.0,.0,1.0); // 黑色
        gl.clear(gl.COLOR_BUFFER_BIT);
        
        gl.useProgram(program);
        gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);

        gl.drawArrays(gl.TRIANGLES, firstIndex, vertexNum);
    }

    function main() {
        const vShader = `
            attribute vec4 a_Position;
            void main() {
                gl_Position = a_Position;
            }
        `;
        const fShader = `
            gl_FragColor = vec4(1.0,0.0,0.0,1.0);
        `;
        let canvas = document.getElementById('myCanvas');
        let gl = canvas.getContext('webgl');
        if(!gl) {
            alert("current browser don't support webgl");
            return;
        }

        _global.gl = gl;

        let vertextData = [.0,.5,-.5,.0,.5,.0];
        let vertextNum = 3;

        // compile shader source
        const program = linkProgram(vShader, fShader);
        setShaderDataFormat(getAttrLocation(program, 'a_Position'), vertextNum, gl.FLOAT)

        // carete data buffer
        const bufferId = createVertexBuffer(vertextData);

        // drawScene
        drawScene(program, bufferId, 0, vertextNum);
    }
    main();
})()