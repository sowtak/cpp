export function useRouter() {
    const routes = new Set < { pattern: string | RegExp, fn: Function} >()
    const route = (pattern: string | RegExp, fn: Function) => {
        routes.add({pattern, fn})
    }

    const exec = (pathname: string = location.pathname) => {
        for (const route of routes) {
            if (typeof route.pattern === "string") {
                if (route.pattern !== pathname) {
                    continue
                }

                return route.fn()
            }

            conts match = route.pattern.exec(pathname)
            if (match === null) {
                continue
            }
        }
    }
}