/**
 * game engine startup.
 */
!(function () {
    // first init global variable
    let _global = typeof window === "undefined" ? global : window.top;

    let logger = {
        log(){
            console.log(...arguments);
        },

        error(){
            console.error(...arguments);
        },

        warn(){
            console.warn(...arguments);
        },

        trace(){
            console.trace(...arguments);
        },

        alert(){
            alert(...arguments);
        },
    }

    function loadShader(type, source) {
        const shader = gl.createShader(type);
        gl.shaderSource(shader, source);
        gl.compileShader(shader);
        if(!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
            logger.error('compile shader fail =>', gl.getShaderInfoLog(shader));
            gl.deleteShader(shader);
            return null;
        }
        return shader;
    }

    function linkProgram(vShaderSource, fShaderSource) {
        let program = gl.createProgram();
        let vShader = loadShader(gl.VERTEX_SHADER, vShaderSource);
        let fShader = loadShader(gl.FRAGMENT_SHADER, fShaderSource);

        gl.attachShader(program,vShader);
        gl.attachShader(program,fShader);
        gl.linkProgram(program);

        let delShader = () => {
            gl.deleteShader(vShader);
            gl.deleteShader(fShader);
        }

        if(!gl.getProgramParameter(program, gl.LINK_STATUS)) {
            logger.error('link program fail =>', gl.getProgramInfoLog(program));
            delShader();
            gl.deleteProgram(program);
            return null;
        }
        delShader();
        return program;
    }

    function createVertexBuffer(data) {
        let bufferId = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.STATIC_DRAW);
        // cancle bind buffer data
        // gl.bindBuffer(gl.ARRAY_BUFFER, null);
        return bufferId;
    }

    function getAttrLocation(shaderProgram, feildName) {
        let location = gl.getAttribLocation(shaderProgram, feildName);
        if(location < 0) {
            logger.error(`获取着色器这个字段${feildName}失败`);
            return;
        }
        return location;
    }

    function getUniformLocation(shaderProgram, feildName) {
        const location = gl.getUniformLocation(shaderProgram, feildName);
        if(location < 0) {
            logger.error(`获取着色器这个字段${feildName}失败`);
            return;
        }
        return location;
    }

    function setShaderDataFormat(locationId, vertexLen, vertexType, normalized, stride, offset) {
        gl.vertexAttribPointer(locationId, vertexLen, vertexType, normalized, stride, offset);
        gl.enableVertexAttribArray(locationId);
    }

    function drawScene(program, data, firstIndex, vertexNum, dt) {
        gl.clearColor(.0,.0,.0,1.0); // 黑色
        gl.clear(gl.COLOR_BUFFER_BIT);

        // calc data
        const fieldOfView = 45 * Math.PI / 180;   // in radians
        const aspect = gl.canvas.clientWidth / gl.canvas.clientHeight;
        const zNear = 0.1;
        const zFar = 1000.0;

        const projectionMatrix = mat4.create();
        mat4.perspective(projectionMatrix, fieldOfView, aspect, zNear, zFar);

        const modelViewMatrix = mat4.create();
        mat4.translate(modelViewMatrix,     // destination matrix
            modelViewMatrix,     // matrix to translate
            [0.0, 0.0, -5]);

        mat4.rotate(modelViewMatrix, modelViewMatrix, data.angle, [0.0,0.0,1.0]);
        

        gl.bindBuffer(gl.ARRAY_BUFFER, data.vertextBufferId);
        gl.bindBuffer(gl.ARRAY_BUFFER, data.colorBufferId);
        gl.useProgram(program);

        gl.uniformMatrix4fv(
            getUniformLocation(program, 'projectionMatrix'),
            false,
            projectionMatrix);
        gl.uniformMatrix4fv(
            getUniformLocation(program, 'modelViewMatrix'),
            false,
            modelViewMatrix);

        gl.drawArrays(gl.TRIANGLES, firstIndex, vertexNum);
    }

    function main() {
        const vShader = `
            attribute vec4 a_Position;
            attribute vec4 a_VertexColor;

            uniform mat4 modelViewMatrix;
            uniform mat4 projectionMatrix;

            varying lowp vec4 vColor;

            void main() {
                gl_Position = projectionMatrix * modelViewMatrix * a_Position;
                vColor = a_VertexColor;
            }
        `;
        const fShader = `
            varying lowp vec4 vColor;

            void main() {
                gl_FragColor = vColor;
            }
        `;
        let canvas = document.getElementById('myCanvas');
        let gl = canvas.getContext('webgl');
        if(!gl) {
            logger.error("current browser don't support webgl");
            return;
        }

        _global.gl = gl;

        let vertextData = [
            0.0,0.5,
            -0.5,0.0,
            0.5,0.0
        ];
        let vertexColor = [
            1.0, 0.0, 0.0, 1.0,
            0.0, 1.0, 0.0, 1.0,
            0.0, 0.0, 1.0, 1.0,
        ];
        let vertextNum = 3;

        // compile shader source
        const program = linkProgram(vShader, fShader);

        // carete data buffer
        const vertextBufferId = createVertexBuffer(vertextData);
        setShaderDataFormat(getAttrLocation(program, 'a_Position'), 2, gl.FLOAT, false, 0, 0);

        // assign vertex color
        const colorBufferId = createVertexBuffer(vertexColor);
        setShaderDataFormat(getAttrLocation(program, 'a_VertexColor'), 4, gl.FLOAT, false, 0, 0);


        let game_time = 0;
        let angle = 0;

        function render(now) {
            now *= 0.001;
            let dt = now - game_time;
            game_time += dt;
            angle += dt;
            // drawScene
            drawScene(program, {
                vertextBufferId : vertextBufferId,
                colorBufferId : colorBufferId,
                angle: angle,
            }, 0, vertextNum, dt);

            requestAnimationFrame(render);    
        }
        requestAnimationFrame(render);
    }
    main();
})();