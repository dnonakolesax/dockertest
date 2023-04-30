--
-- PostgreSQL database dump
--

-- Dumped from database version 14.5 (Debian 14.5-2.pgdg110+2)
-- Dumped by pg_dump version 14.5 (Debian 14.5-2.pgdg110+2)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: testdocker; Type: SCHEMA; Schema: -; Owner: habrpguser
--

CREATE SCHEMA testdocker;


ALTER SCHEMA testdocker OWNER TO habrpguser;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: example; Type: TABLE; Schema: testdocker; Owner: habrpguser
--

CREATE TABLE testdocker.example (
    id integer NOT NULL,
    text character varying(100) NOT NULL
);


ALTER TABLE testdocker.example OWNER TO habrpguser;

--
-- Data for Name: example; Type: TABLE DATA; Schema: testdocker; Owner: habrpguser
--

COPY testdocker.example (id, text) FROM stdin;
1       uzbek
2       tadjik
3       kirgiz
\.


--
-- Name: example example_pkey; Type: CONSTRAINT; Schema: testdocker; Owner: habrpguser
--

ALTER TABLE ONLY testdocker.example
    ADD CONSTRAINT example_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--
